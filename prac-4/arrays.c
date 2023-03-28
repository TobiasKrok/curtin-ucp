#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrays.h"

int main() {

    int arr[] = {10, 20, 30};
    int *arr2 = (int*)malloc(sizeof(int) * 3);
    fill_values(arr2, 3, 5);
    fill_values(arr, 3, 104545);

    printf("%d \n", sum(arr2, 3));
    printf("%d \n", sum(arr, 3));

    return 0;
}

int sum(int *array, int size) {

    int i;
    int res;
    res = 0;
    for(i = 0; i < size; i++ ) {
        printf("%d \n", array[i]);
        res += array[i];
    }

    return res;
}

int max(int *array, int size) {

    int res;
    res = array[0];
    int i;
    for(i = 1; i < size; i++) {
        if(array[i] > res) {
            res = array[]
        }
    } 
    return 0;
}


void fill_values(int* arr, int size, int value) {

    int i;
    for(i = 0; i < size; i++) {
        arr[i] = value;
    }
}