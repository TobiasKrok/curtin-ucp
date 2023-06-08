#include <stdlib.h>
#include "macros.h"

/**
 * Helper function to create a 2d int array and optionally fill it with zero
 * @param rows Amount of rows
 * @param cols Amount of columns
 * @param fill_with_zero Whether or not the array should be filled with zero
 * @return Pointer to a 2D int array
 */
int **create_2d_array(int rows, int cols, Bool fill_with_zero)
{
    int i;
    int **arr = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    if (fill_with_zero == TRUE)
    {
        int k;
        for (i = 0; i < rows; i++)
        {
            for (k = 0; k < cols; k++)
            {
                arr[i][k] = 0;
            }
        }
    }
    return arr;
}

/**
 * Copies the contents of a 2D int array to another 2D int array
 * The function assumes that no arrays are null and they are equal in size
 *
 * @param source The array to copy from
 * @param dest The array to copy to
 * @param rows Amount of rows
 * @param cols Amount of columns
 */
void copy_2d_int_array(int **source, int **dest, int rows, int cols)
{

    int i, k;

    for (i = 0; i < rows; i++)
    {
        for (k = 0; k < cols; k++)
        {
            dest[i][k] = source[i][k];
        }
    }
}

/**
 * Helper function to free a 2d int array
 * The function assumes that the array is not null
 * @param array The 2D array to free
 * @param rows The amount of rows
 */
void free_2d_int_array(int **array, int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}