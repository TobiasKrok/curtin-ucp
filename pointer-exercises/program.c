#include <stdio.h>
#include <stdlib.h>

int sum_ptr_arithmetic(int *arr, int size)
{

    int i;
    int res = 0;
    for (i = 0; i < size; i++)
    {
        res += *arr;
        arr++;
    }

    return res;
}

void min_max_ptr_arithmetic(int arr[], int size, int *min, int *max)
{

    int i;
    *min = *arr;
    *max = 0;
    for (i = 0; i < size; i++)
    {
        if (*arr < *min)
        {
            *min = *arr;
        }
        if (*arr > *max)
        {
            *max = *arr;
        }
        arr++;
    }
}

int str_len(char *str)
{

    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

/*
This generates a memory leak unless freed
*/
char *strconcat(char *str1, char *str2)
{
    int str1_len = str_len(str1);
    int str2_len = str_len(str2);
    int new_len = str1_len + str2_len;
    char *str = (char *)malloc(sizeof(char) * new_len + 1);
    int i;
    int y;
    for (i = 0; i < str1_len; i++)
    {
        if (str1[i] != '\0')
        {
            str[i] = str1[i];
        };
    }
    for (y = 0; y < str2_len; y++)
    {
        if (str2[y] != '\0')
        {
            str[y + i] = str2[y];
        };
    }
    str[new_len] = '\0';

    return str;
}

/*
ChatGPT solution:

void concatenate(char *destination, const char *source) {
    // Move the pointer to the end of the destination string
    while (*destination) {
        destination++;
    }

    // Copy characters from the source string to the destination string
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }

    // Add the null terminator at the end of the concatenated string
    *destination = '\0';
}

*/

void strreverse(char *str, int size)
{

    char **ptr = &str;
    int i;

    ptr = ptr + size - 1;

    for (i = 0; i < size; i++)
    {
        char tmp = *str;

        *str = **ptr;
        **ptr = tmp;
        str++;
        ptr--;
    }
}
int main()
{

    int arr[] = {1, 2, 3, 4};
    int min, max;
    char *str = "Hey man!";
    char *str2 = " How are you?";
    char *concat = strconcat(str, str2);
    min_max_ptr_arithmetic(arr, 4, &min, &max);
    printf("%d \n", sum_ptr_arithmetic(arr, 4));
    printf("min: %d, max: %d \n", min, max);
    printf("len:%d string: %s \n", str_len(str), str);
    printf("concatted string: %s \n", concat);
    strreverse(str, str_len(str));
    printf("reversed: %s\n", str);
    return 0;
}
