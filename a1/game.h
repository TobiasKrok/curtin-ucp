#ifndef GAME_H
#include "input.h"
#define GAME_H
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
    char **map;
} Map;
Map *create_game(GameInput game_input);
void print_map(Map *map, GameInput game_input);
void start_game(Map *map, GameInput game_input);
#endif