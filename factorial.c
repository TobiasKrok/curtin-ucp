#include <stdlib.h>
#include <stdio.h>

int factorial(int n ) {

    int fact;

    int i;
    for(i = n; i  n; i--) {
        if(!(i - 1) == 0) {
            printf("%d %d \n", n, (n - 1));
            fact += i * (i - 1);
        } 
    }

    return fact;
}

int main(void) {

printf("%d", factorial(7));
return 0;
}


