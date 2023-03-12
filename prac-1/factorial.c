#include <stdlib.h>
#include <stdio.h>

int factorial(int n) {

    int fact = 1;

    int i;
    for(i = 2; i <= n; i++) {
        fact *= i; 
    }

    return fact;
}

int main(void) {

printf("%d \n", factorial(7));
return 0;
}


