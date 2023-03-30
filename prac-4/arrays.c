#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrays.h"

int sum(int *array, int size)
{

    int i;
    int res;
    res = 0;
    for (i = 0; i < size; i++)
    {
        res += array[i];
    }

    return res;
}

int maxv(int *array, int size)
{

    int res;
    int i;
    res = 0;
    for (i = 1; i < size; i++)
    {
        if (array[i] > res)
        {
            res = i;
        }
    }
    return res;
}

void reverse(int *array, int size)
{

    int i;
    int k;
    k = size - 1;
    while (i < k)
    {
        int tmp = array[i];
        array[i] = array[k];
        array[k] = tmp;
        k--;
        i++;
    }
}

void fill_values(int *arr, int size, int value)
{

    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("%c", '{');
        }
        if (i == size - 1)
        {
            printf("%d", arr[i]);
            printf("%c", '}');
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
    printf("\n");
}

void charArrToIntArr(char **charArr, int *intArr, int lenght)
{

    int i;
    for (i = 0; i < lenght; i++)
    {
        intArr[i] = atoi(charArr[i]);
    }
}

void charArrFromIndex(char **charArr, int size, int start, char **result)
{
    int i;
    int k = 0;
    for (i = start; i < size; i++)
    {
        result[k] = charArr[i];
        k++;
    }
}