#include<stdio.h>
#include"color.h"

int main()
{
	int r, c;

	printf("\nno background color\n");

	setBackground("blue");
	printf("blue background");
	setBackground("reset");
	printf("\n");

	setBackground("red");
	printf("red background");
	setBackground("reset");
	printf("\n");

	printf("back to no color\n\n");


	for(r = 0 ; r < 5 ; r++)
	{
		for(c = 0 ; c < 10 ; c++)
		{
			if(r == 3 && c == 8)
			{
				setBackground("green");
			}

			printf("-");

			setBackground("reset");
		}
		printf("\n");

	}

	return 0;
}
