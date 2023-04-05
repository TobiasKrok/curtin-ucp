#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "arrays.h"
#include "input.h"
#include "game.h"
#include "random.h"

int main(int argc, char **argv)
{
    /* This will hold inputs converted to int. We do argc - 1 because we omit the first element
    in argc which is the file name
    */
    int *user_inputs = NULL;
    GameInput *input;
    int is_error = FALSE;
    ValidationResult *validation_result = NULL;
    Map *map = NULL;

    /* Seed random */
    initRandom();
    /* Convert argv to int array, removing the first element (executable name)*/
    user_inputs = (int *)malloc((sizeof(int) * argc) - 1);
    convert_char_arr_to_int_arr(argv, user_inputs, argc, 1);

    /* Create GameIbput struct based on the user input*/
    input = map_argv_to_game_input(user_inputs);
#ifdef DEBUG
    printf("argc: %d, map_row: %d map_col: %d player_row: %d player_col: %d goal_row: %d goal_col: %d \n", argc, input->MAP_COL, input->MAP_ROW, input->PLAYER_ROW, input->PLAYER_COL, input->GOAL_ROW, input->GOAL_COL);
#endif
    /* Validate input and get the results*/
    validation_result = validate_args(argc, *input);
    /*
    Print the error message if there is one, otherwise start the game
   */
    if (validation_result->is_error == TRUE)
    {
        printf("%s \n", validation_result->error_message);
        is_error = TRUE;
    }
    else
    {
        /* Game logic */

        /* Initializes and creates the map based on input*/
        map = create_game(*input);
        /* Starts the game. It will loop until finished*/
        start_game(map);
        printf("Game over! You win!!\n");

        /* Free the game map, this is only needed if the game actually starts (ie no error)*/
        free_map(map);
    }
    /* Free everything */
    free(input);
    free(user_inputs);
    free_validation_result(validation_result);
    return is_error;
}