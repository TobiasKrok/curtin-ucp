#ifndef GAME_H
#define GAME_H
#include "input.h"


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

#endif