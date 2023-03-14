#include<stdio.h>
#include<math.h>
int power(void) {
    static int counter = 2;
    int power = pow(2, counter);
    counter++;

    return power;
}


int main() {

    printf("%d \n", power());
    printf("%d \n", power());
    printf("%d \n", power());
    printf("%d \n", power());
    printf("%d \n", power());
    printf("%d \n", power());
    printf("%d \n", power());



    return 0;
}