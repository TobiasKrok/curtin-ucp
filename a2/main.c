#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "macros.h"
#include "game.h"

int main(int argc, char **argv)
{
    GameInput *game_input = (GameInput *)malloc(sizeof(GameInput));
    /* Validate input and read map file */
    OperationResult validation_res = validate_args(argc, argv);
    OperationResult read_map_res = read_map_file(argv, game_input);
    Map *map = NULL;
    if (validation_res.is_error == TRUE)
    {
        printf("%s\n", validation_res.error_message);
    }
    else if (read_map_res.is_error == TRUE)
    {
        printf("%s\n", read_map_res.error_message);
    }
    else
    {
        /* Everything is good, let's create and start the game*/
        map = create_game(*game_input);
        start_game(map);
        printf("Game Over! You win!!\n");
        /* Only free the map if the game has actually started*/
        free_map(map);
    }
    free(game_input->walls_pos);
    free(game_input);

    return (read_map_res.is_error == TRUE || validation_res.is_error == TRUE);
}