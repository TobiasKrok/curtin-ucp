#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "input.h"
#include "macros.h"
#include "random.h"
#include "terminal.h"
#include "game.h"
/*

* * * * * * *
*           *
*           *
*           *
* * * * * * *
*/

/* Initializes the game by creating the map and placing the player, goal and box on the map*/
Map *create_game(GameInput game_input)
{

    /* Create a 2D array containing char arrays
    We're using double pointer because it's an array of malloced arrays
    */
    char **arr = (char **)malloc(sizeof(char *) * game_input.MAP_ROW);
    int i, k, box_row, box_col;
    int isValid = FALSE;
    Map *map = (Map *)malloc(sizeof(Map));

    /* Initialize columns in map*/
    for (i = 0; i < game_input.MAP_ROW; i++)
    {
        /* Initialize each column. Each row is a pointer to another array*/
        arr[i] = (char *)malloc(sizeof(char) * game_input.MAP_COL);
    }
    /* Set the value for all cells to ' ' */
    for (k = 0; k < game_input.MAP_ROW; k++)
    {
        for (i = 0; i < game_input.MAP_COL; i++)
        {
            arr[k][i] = ' ';
        }
    }
    /* Set the position of the goal and the player
    Input validation should make sure that these do not overlap or is out of bounds
    */
    arr[game_input.GOAL_ROW][game_input.GOAL_COL] = 'G';
    arr[game_input.PLAYER_ROW][game_input.PLAYER_COL] = 'P';

    /* Randomly generate the box position. To make sure the box won't overlap with player or goal, or is placed on the border,
    we loop until the position is valid (aka no overlap)
     */
    while (isValid == FALSE)
    {
        box_row = randomUCP(0, game_input.MAP_ROW - 1);
        box_col = randomUCP(0, game_input.MAP_COL - 1);

        int is_on_border = (box_row == 0 || box_row == game_input.MAP_ROW - 1 || box_col == 0 || box_col == game_input.MAP_COL - 1);
        int not_overlapping = (box_row != game_input.GOAL_ROW && box_col != game_input.GOAL_COL) == TRUE && (box_row != game_input.PLAYER_ROW && box_col != game_input.PLAYER_COL) == TRUE;
        if (is_on_border == FALSE && not_overlapping == TRUE)
        {
            isValid = TRUE;
        }
    }

    arr[box_row][box_col] = 'B';
    map->map = arr;
    map->columns = game_input.MAP_COL;
    map->rows = game_input.MAP_ROW;
    return map;
}

/* Prints the map */
void print_map(Map *map, GameInput game_input)
{
    int i, k;
    /* We add + 2 to the MAP_ROW/COL because we want the bands to "wrap around" the actual playable map
       This adds one char padding around the map, which will look like the border
    */
    for (i = 0; i < map->rows + 2; i++)
    {
        for (k = 0; k < map->columns + 2; k++)
        {
            /* If the index is the first/last row or first column*/
            if (i == 0 || i == map->rows + 1 || k == 0)
            {
                printf("* ");
            }
            /* If the index is the last column*/
            else if (k == map->columns + 1)
            {
                printf("*");
            }
            else
            {
                /* Print and color the G. It will be red if the box is not in goal, green if it is*/
                if (map->map[i - 1][k - 1] == 'G')
                {
                    setBackground("red");
                    printf("%c ", map->map[i - 1][k - 1]);
                    setBackground("reset");
                }
                else
                {
                    printf("%c ", map->map[i - 1][k - 1]);
                }
            }
        }
        printf("\n");
    }
}

char get_input()
{
    char c;

    disableBuffer();
    scanf(" %c", &c);
    enableBuffer();
    system("clear");

    return c;
}

void move_player(Map *map, Direction direction)
{

    switch (direction)
    {
    case UP:

        break;

    default:
        break;
    }
}

void start_game(Map *map, GameInput game_input)
{

    int game_over = FALSE;
    char input;
    while (game_over == FALSE)
    {
        print_map(map, game_input);
        printf("%s\n", "Press w to move UP");
        printf("%s\n", "Press a to move LEFT");
        printf("%s\n", "Press s to move DOWN");
        printf("%s\n", "Press d to move RIGHT");
        input = get_input();

        switch (input)
        {
        case 'w':

            break;
        }
    }
}
