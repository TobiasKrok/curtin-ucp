#include "order.h"
#include <stdio.h>

int main(){

    int bigger;
    int big;
    int small;
    big = 400;
    small = 200;
    bigger = 1000;

    /* printf("big: %d \n", big);
    printf("small: %d \n", small);
    ascending2(&big, &small);

    printf("big: %d \n", big);
    printf("small: %d \n", small); */

    ascending3(&big, &small, &bigger);
    printf("bigger: %d \n", bigger);
        printf("big: %d \n", big);
    printf("small: %d \n", small);



    return 0;
}