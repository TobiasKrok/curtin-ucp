#include <stdio.h>
#include <math.h>
int power(void)
{
    static int counter = 1;
    int power = pow(2, counter);
    counter++;

#ifdef DEBUG
    printf("DEBUG: power is %d \n", power);
#endif
    return power;
}
