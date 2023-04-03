#include <stdlib.h>
#include <stdio.h>
/*
Converts a char arr to an int array.
You can specify the start index so you can omit the first argument passed by argv if needed
*/
void charArrToIntArr(char **charArr, int *intArr, int size, int startIndex)
{

    int i;
    for (i = startIndex; i < size; i++)
    {
        intArr[i - startIndex] = atoi(charArr[i]);
    }
}

void set_2d_arr_pos(int *arr, int row, int col, int value)
{
}