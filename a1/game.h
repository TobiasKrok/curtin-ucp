#ifndef GAME_H
#include "input.h"
#define GAME_H

/* Contains the position of an object on the map */
typedef struct point
{
    int col;
    int row;
} Point;

/* Defines move actions for player */
typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
} Direction;
/* Contains the map and its size */
typedef struct map
{
    int rows;
    int columns;
    Point player_pos;
    Point box_pos;
    Point goal_pos;
    char **map;
} Map;
Map *create_game(GameInput game_input);
void print_map(Map *map, GameInput game_input);
void start_game(Map *map, GameInput game_input);
#endif