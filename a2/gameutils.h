#ifndef GAMEUTILS_H
#define GAMEUTILS_H
#include "game.h"

char get_input();
int is_box_adjacent(Map *map, Direction direction);
int is_move_oob(Map *map, Direction direction, int box_adjacent);
void undo_move(Map *map);
void move(Map *map, Direction direction, char c, Point *object, int link_previous_move, int leave_trail);

#endif