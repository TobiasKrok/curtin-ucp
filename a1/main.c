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
    int *user_inputs;
    const GameInput *input;
    ValidationResult *validation_result;
    Map *map;

    /* Seed random */
    initRandom();
    /* Convert argv to int array*/
    user_inputs = (int *)malloc((sizeof(int) * argc) - 1);
    convert_char_arr_to_int_arr(argv, user_inputs, argc, 1);

    /*TODO: FREE*/
    input = map_argv_to_game_input(user_inputs);
#ifdef DEBUG
    printf("argc: %d, map_row: %d map_col: %d player_row: %d player_col: %d goal_row: %d goal_col: %d \n", argc, input->MAP_COL, input->MAP_ROW, input->PLAYER_ROW, input->PLAYER_COL, input->GOAL_ROW, input->GOAL_COL);
#endif
    validation_result = validate_args(argc, *input);
    /*
   Stop the program if any arguments were invalid and print error, free any used memory
   */
    if (validation_result->is_error == TRUE)
    {

        printf("%s \n", validation_result->error_message);
        free_validation_result(validation_result);
        return 1;
    }
    /* Free malloced vars used for validation */
    free(user_inputs);
    free_validation_result(validation_result);

    /* Game logic */
    map = create_game(*input);
    start_game(map, *input);
    return 0;
}