#include <stdlib.h>
#include <stdio.h>
#include "game.h"
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

