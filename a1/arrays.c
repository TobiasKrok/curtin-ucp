#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"
/*
Converts a char arr to an int array.
You can specify the start index so you can omit the first argument passed by argv if needed
*/
void convert_char_arr_to_int_arr(char **charArr, int *intArr, int size, int startIndex)
{

    int i;
    for (i = startIndex; i < size; i++)
    {
        intArr[i - startIndex] = atoi(charArr[i]);
    }
}

/* Helper function to find the index of passed chars. Used to find where the player, box and goal is on the map*/
Point find_index_char(char **arr, int rows, int cols, char c)
{
    int i, k;
    Point p = {-1, -1};
    for (i = 0; i < rows; i++)
    {
        for (k = 0; k < cols; k++)
        {
            if (arr[i][k] == c)
            {
                p.row = i;
                p.col = k;
            }
        }
    }
    return p;
}