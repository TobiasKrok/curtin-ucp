#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
    /* TODO: free*/
    Map *map = (Map *)malloc(sizeof(Map));
    Point player_pos = {-1, -1};
    Point goal_pos = {-1, -1};
    Point box_pos = {-1, -1};

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
        int is_on_border, not_overlapping;
        /* Generate random row and columns for box*/
        box_row = randomUCP(0, game_input.MAP_ROW - 1);
        box_col = randomUCP(0, game_input.MAP_COL - 1);

        /* Checks if the randomly generated row/col would be on the border*/
        is_on_border = (box_row == 0 || box_row == game_input.MAP_ROW - 1 || box_col == 0 || box_col == game_input.MAP_COL - 1);
        /* Checks if the randomly generated row/col would overlap with the goal or player*/
        not_overlapping = (box_row != game_input.GOAL_ROW && box_col != game_input.GOAL_COL) == TRUE && (box_row != game_input.PLAYER_ROW && box_col != game_input.PLAYER_COL) == TRUE;
        if (is_on_border == FALSE && not_overlapping == TRUE)
        {
            isValid = TRUE;
        }
    }
    /* Place the box on the map*/
    arr[box_row][box_col] = 'B';

    /* Initialize the Point variables with the default position*/
    player_pos.row = game_input.PLAYER_ROW;
    player_pos.col = game_input.PLAYER_COL;

    goal_pos.row = game_input.GOAL_ROW;
    goal_pos.col = game_input.GOAL_COL;

    box_pos.row = box_row;
    box_pos.col = box_row;

    /* Initialize properties of our map.*/
    map->map = arr;
    map->columns = game_input.MAP_COL;
    map->rows = game_input.MAP_ROW;
    map->player_pos = player_pos;
    map->goal_pos = goal_pos;
    map->box_pos = box_pos;
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

/* Checks if the potential move would be out of bounds*/
int is_move_oob(Map *map, Direction direction) {
    int is_oob = FALSE;

    switch(direction) {
        case UP:
        /* If the player moves one row up */
        if(map->player_pos.row - 1 < 0) {
            is_oob = TRUE;
        }
        break;

    }

    return is_oob;
}
void move_player(Map *map, Direction direction)
{

    switch (direction)
    {
    case UP:
    if(is_move_oob(map, direction) == FALSE) {

        map->map[map->player_pos.row][map->player_pos.col] = ' ';
        map->map[map->player_pos.row - 1][map->player_pos.col] = 'P';
        map->player_pos.row -= 1;
    }

        break;
    case DOWN:
      map->map[map->player_pos.row][map->player_pos.col] = ' ';
        map->map[map->player_pos.row + 1][map->player_pos.col] = 'P';
        map->player_pos.row += 1;
    break;
     case RIGHT:
      map->map[map->player_pos.row][map->player_pos.col] = ' ';
        map->map[map->player_pos.row][map->player_pos.col + 1] = 'P';
        map->player_pos.col += 1;
    break;
    case LEFT:
      map->map[map->player_pos.row][map->player_pos.col] = ' ';
        map->map[map->player_pos.row][map->player_pos.col - 1] = 'P';
        map->player_pos.col -= 1;
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
        move_player(map, UP);
        break;
        case 's':
        move_player(map, DOWN);
        break;
        case 'd':
        move_player(map, RIGHT);
        break;
        case 'a':
        move_player(map, LEFT);
        
        }
    }
}


/*

struct Struct1 {
    int x;
    int y;
}


struct Struct2 {
    int z;
    struct Struct1 other;
}

struct Struct2 blah;


int *p = &blah.other.z;

struct Struct1* pp = &blah.other;



*/
