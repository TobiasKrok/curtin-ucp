#include "macros.h"
#include<stdio.h>

int check_bounds(int low, int high, int value) {


    return value >= low && value <= high ? TRUE : FALSE;
}


int main() {

    printf("%d", check_bounds(5,10, 11));
    printf("%d", BETWEEN(5,10, 11));

    return 0;
}