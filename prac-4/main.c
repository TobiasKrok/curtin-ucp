#include "arrays.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 10
int main(int argc, char *argv[])
{

    int arr[] = {10, 20, 30, 40};
    int *arr2 = (int *)malloc(sizeof(int) * 3);
    fill_values(arr2, 3, 5);
    reverse(arr, 4);
    print_array(arr, 4);

    return 0;
}

/* int arr[] = {10, 20, 30};
int *arr2 = (int *)malloc(sizeof(int) * 3); */
/*     fill_values(arr2, 3, 5);
    reverse(arr, 3);
    printArray(arr, 3);
 */

/*  char *cArr[5] = {"21", "4", "7", "4", "-999"};
 int iArr[5];
 memset(iArr, 0, sizeof(int) * 5);
 charArrToIntArr(cArr, iArr, 5);
 print_array(iArr, 5); */

/* void (*rev_ptr)(int *, int) = NULL;
int (*int_ptr)(int *, int) = NULL;

if (argc < 2)
{
       printf("%s", "Usage: <sum | reverse | max | blank> <int[10]>...");
       return 1;
}
if (argc > MAX_ARR_SIZE)
{
       printf("%s", "Maximum 10 arguments are allowed");
       return 1;
}

if (strcmp(argv[1], "sum") == 0)
{
       int_ptr = &sum;
}
else if (strcmp(argv[1], "reverse") == 0)
{
       rev_ptr = &reverse;
}
else if (strcmp(argv[1], "max") == 0)
{
       int_ptr = &maxv;
}

int *arr = (int *)malloc(sizeof(int) * argc - 1);
free(arr); */
