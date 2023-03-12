#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>

int main()
{
    int n1 = 0;
    int n2 = 0;

    while (n1 == 0 || n2 == 0)
    {
        printf("Number 1: ");
        scanf("%d", &n1);

        printf("Number 2: ");
        scanf("%d", &n2);

        if(n1 == 0 || n2 == 0) {
            printf("Inputs cannot be 0 \n");
            sleep(2);
        }
    }
    
    if ((n1 % n2) == 0)
    {
        printf("Divisible \n ");
    }
    else
    {
        printf(" Not divisible \n");
    }
    return 0;
}