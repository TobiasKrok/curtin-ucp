#include "http.h"
#include "ping.h"
#include <stdio.h>

int main()
{
    initiate_req("10.70.45.2");
    ping("192.168.1.5");

#ifdef DEBUG
    printf("Debug mode is on");
#endif
    return 0;
}