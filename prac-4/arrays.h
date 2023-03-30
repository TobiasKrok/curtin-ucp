#ifndef ARRAYS_H
#define ARRAYS_H

int sum(int *array, int size);
int maxv(int *array, int size);
void fill_values(int *arr, int size, int value);
void print_array(int arr[], int size);
void reverse(int *array, int size);
void charArrToIntArr(char **charArr, int *intArr, int lenght);
void charArrFromIndex(char **charArr, int size, int start, char **result);

#endif