#ifndef ARRAYS_H
#define ARRAYS_H
/* Used to return the current index of objects on the map*/
typedef struct point
{
    int col;
    int row;
} Point;
void convert_char_arr_to_int_arr(char **charArr, int *intArr, int size, int startIndex);
Point find_index_by_char(char **arr, int rows, int cols, char c);
#endif