#ifndef GAME_H
#include "input.h"
#define GAME_H

char **create_game(GameInput game_input);
void print_map(char **map, GameInput game_input);
#endif