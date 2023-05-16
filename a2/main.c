#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "macros.h"
#include "game.h"

int main(int argc, char **argv)
{
    GameInput *game_input = (GameInput *)malloc(sizeof(GameInput));
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
        map = create_game(*game_input);
        start_game(map);
        printf("Game Over! You win!!\n");
        free_map(map);
    }
    free(game_input->walls_pos);
    free(game_input);

    return (read_map_res.is_error == TRUE || validation_res.is_error == TRUE);
}