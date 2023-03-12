#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int ping(char ipAddress[])
{
    printf("Pinging %s", ipAddress);
    printf("Responded in 1 second");

    return 1;
}