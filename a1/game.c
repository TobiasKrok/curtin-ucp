#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "input.h"

/*

* * * * * * *
*           *
*           *
*           *
* * * * * * *
*/

/* Initializes the game by creating the map and placing the player, goal and box on the map*/
char **create_game(GameInput game_input)
{
    /* Create a 2D array containing char arrays
    We're using double pointer because it's an array of malloced arrays
    */
    char **map = (char **)malloc(sizeof(char *) * game_input.MAP_ROW);
    int i, k;
    /* Initialize columns in map*/
    for (i = 0; i < game_input.MAP_ROW; i++)
    {
        map[i] = (char *)malloc(sizeof(char) * game_input.MAP_COL);
    }
    for (k = 0; k < game_input.MAP_ROW; k++)
    {
        for (i = 0; i < game_input.MAP_COL; i++)
        {
            if (k == 0 || i == game_input.MAP_COL - 1 || i == 0 || k == game_input.MAP_ROW - 1)
            {
                map[k][i] = '*';
            }
            else
            {
                map[k][i] = ' ';
            }
        }
    }

    map[game_input.GOAL_ROW][game_input.GOAL_COL] = 'G';
    map[game_input.PLAYER_ROW][game_input.PLAYER_COL] = 'P';

    return map;
}

void print_map(char **map, GameInput game_input)
{
    int i, k;
    for (i = 0; i < game_input.MAP_ROW; i++)
    {
        for (k = 0; k < game_input.MAP_COL; k++)
        {
            if (map[i][k] == 'G')
            {
                setBackground("red");
                printf("%c ", map[i][k]);
                setBackground("reset");
            }
            else
            {
                printf("%c ", map[i][k]);
            }
        }
        printf("\n");
    }
}