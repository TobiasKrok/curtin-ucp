#include<stdio.h>
#include"random.h"

int main()
{
	int i;

	initRandom(); /* initialize the seed */

	for(i = 0 ; i < 10 ; i++)
	{
		printf("random integer -> %d\n", randomUCP(1,5));
	}

	return 0;
}
