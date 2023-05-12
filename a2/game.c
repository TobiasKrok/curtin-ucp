#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "color.h"
#include "input.h"
#include "macros.h"
#include "terminal.h"
#include "game.h"
#include "linkedlist.h"
#include "gameutils.h"

/**
 * Prints the game map
 * @private
 * @param map Pointer to the game map
 * @returns void
 */
void print_map(Map *map)
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
                /* Print and color the goal character. If the player is on top of the goal, it will also get the red background. */
                if (map->map[i - 1][k - 1] == 'G' || (map->map[i - 1][k - 1] == 'P' && (map->player_pos.col == map->goal_pos.col && map->player_pos.row == map->goal_pos.row)))
                {
                    setBackground("red");
                    printf("%c ", map->map[i - 1][k - 1]);
                    setBackground("reset");
                }
                /*If the box position is at the goal position, we make it green*/
                else if (map->map[i - 1][k - 1] == 'B' && map->box_pos.row == map->goal_pos.row && map->box_pos.col == map->goal_pos.col)
                {
                    setBackground("green");
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

/**
 * Handles bounds checking and moves objects on the map
 * This includes the box and the player. If PULL is defined, the box can be dragged by the player
 * @private
 * @param map A pointer to the game map
 * @param direction The direction the player wants to move
 * @returns void
 */
void move_object(Map *map, Direction direction)
{

    int box_adjacent = is_box_adjacent(map, direction);

    switch (direction)
    {
    case UP:
        if (is_move_oob(map, UP, box_adjacent) == FALSE)
        {
            if (box_adjacent == TRUE)
            {
                move(map, UP, 'B', &map->box_pos, FALSE);
            }
            move(map, UP, 'P', &map->player_pos, box_adjacent);
        }
        break;
    case DOWN:
        if (is_move_oob(map, direction, box_adjacent) == FALSE)
        {
            if (box_adjacent == TRUE)
            {
                move(map, DOWN, 'B', &map->box_pos, FALSE);
            }
            move(map, DOWN, 'P', &map->player_pos, box_adjacent);
        }

        break;
    case RIGHT:
        if (is_move_oob(map, direction, box_adjacent) == FALSE)
        {
            if (box_adjacent == TRUE)
            {
                move(map, RIGHT, 'B', &map->box_pos, FALSE);
            }

            move(map, RIGHT, 'P', &map->player_pos, box_adjacent);
        }

        break;
    case LEFT:
        if (is_move_oob(map, direction, box_adjacent) == FALSE)
        {
            if (box_adjacent == TRUE)
            {
                move(map, LEFT, 'B', &map->box_pos, FALSE);
            }
            move(map, LEFT, 'P', &map->player_pos, box_adjacent);
        }
        break;
    default:
        break;
    }
}

/**
 * Creates the game map based on the user input
 * @param game_input Struct of user input
 * @public
 * @returns Map*
 */
Map *create_game(GameInput game_input)
{

    /* Create a 2D array containing char arrays
    We're using double pointer because it's an array of malloced arrays
    */
    char **arr = (char **)malloc(sizeof(char *) * game_input.rows);
    int i, k;
    LinkedList *move_history = ll_create();
    Map *map = (Map *)malloc(sizeof(Map));

    /* Initialize columns in map*/
    for (i = 0; i < game_input.rows; i++)
    {
        /* Initialize each column. Each row is a pointer to another array*/
        arr[i] = (char *)malloc(sizeof(char) * game_input.cols);
    }
    /* Set the value for all cells to ' ' */
    for (k = 0; k < game_input.rows; k++)
    {
        for (i = 0; i < game_input.cols; i++)
        {
            arr[k][i] = ' ';
        }
    }

    /* Set the walls of the map*/
    for (i = 0; i < game_input.walls_count; i++)
    {
        arr[game_input.walls_pos[i].row][game_input.walls_pos[i].col] = 'O';
    }

    /* Set the position of the goal and the player
     */
    arr[game_input.goal_pos.row][game_input.goal_pos.col] = 'G';
    arr[game_input.player_pos.row][game_input.player_pos.col] = 'P';

    /* Place the box on the map*/
    arr[game_input.box_pos.row][game_input.box_pos.col] = 'B';

    /* Initialize properties of our map.*/
    map->box_pos = game_input.box_pos;
    map->goal_pos = game_input.goal_pos;
    map->player_pos = game_input.player_pos;
    map->map = arr;
    map->columns = game_input.cols;
    map->rows = game_input.rows;
    map->move_history = move_history;

    return map;
}

/**
 * Starts the game loop
 * @public
 * @param map Pointer to the game map
 * @returns void
 */
void start_game(Map *map)
{

    int game_over = FALSE;
    char input;

    while (game_over == FALSE)
    {
        system("clear");
        print_map(map);
        printf("%s\n", "Press w to move UP");
        printf("%s\n", "Press a to move LEFT");
        printf("%s\n", "Press s to move DOWN");
        printf("%s\n", "Press d to move RIGHT");
        printf("%s\n", "Press u to undo");
        input = get_input();

        switch (input)
        {
        case 'w':
            move_object(map, UP);
            break;
        case 's':
            move_object(map, DOWN);
            break;
        case 'd':
            move_object(map, RIGHT);
            break;
        case 'a':
            move_object(map, LEFT);
            break;
        case 'u':
            undo_move(map);
            break;
        default:
            break;
        }

        /* If the box is on the goal position, end the loop and print the map one last time*/
        if (map->box_pos.row == map->goal_pos.row && map->box_pos.col == map->goal_pos.col)
        {
            system("clear");
            game_over = TRUE;
            print_map(map);
        }
    }
}
/**
 * Helper function to free the game map
 * @public
 * @param map Pointer to the game map
 * @returns void
 */
void free_map(Map *map)
{
    int i;
    for (i = 0; i < map->rows; i++)
    {
        free(map->map[i]);
    }
    free(map->map);
    free(map);
}