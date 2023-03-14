#include "macros.h"
#include <stdio.h>
#include "powers.h"

int main()
{

    int times;

    scanf("%d", &times);

    if (BETWEEN(1, 31, times) == TRUE)

#ifdef DEBUG
        printf("DEBUG: times is %d \n", times);
#endif
    {
        int i;
        for (i = 0; i < times; i++)
        {
            printf("%d \n", power());
        }
    }

    return 0;
}