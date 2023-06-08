#ifndef ARRAYS_H
#include "macros.h"
#define ARRAYS_H

int **create_2d_array(int rows, int cols, Bool fill_with_zero);
void copy_2d_int_array(int **source, int **dest, int rows, int cols);
void free_2d_int_array(int **array, int rows);
#endif