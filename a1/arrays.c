#include <stdlib.h>
#include <stdio.h>
#include "game.h"
/**
 * Converts a char array to an int array
 * @public
 * @param charArr the char array to convert
 * @param intArr the int array to convert to
 * @param size the size of the char array
 * @param startIndex the index to start converting from
 * @return void
 */
void convert_char_arr_to_int_arr(char **charArr, int *intArr, int size, int startIndex)
{

    int i;
    for (i = startIndex; i < size; i++)
    {
        intArr[i - startIndex] = atoi(charArr[i]);
    }
}
