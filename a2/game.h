#ifndef GAME_H
#define GAME_H
#include "input.h"
#include "linkedlist.h"

/* Defines move actions for player */
typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
} Direction;

typedef struct move
{
    Point *from;
    Point *to;
    Point *object;
    char object_char; /* Which object we are moving */
    char old_char;    /* The character that was at the previous spot. Ensures that we dont overwrite the goal for instance*/
    int is_chained;   /* If the move is chained, it means that when undoing we need to undo the previous move as well*/
} Move;

/* Contains the map and its size */
typedef struct map
{
    int rows;
    int columns;
    Point player_pos;
    Point box_pos;
    Point goal_pos;
    char **map;
    LinkedList *move_history;

} Map;
Map *create_game(GameInput game_input);
void print_map(Map *map);
void start_game(Map *map);
void free_map(Map *map);
#endif