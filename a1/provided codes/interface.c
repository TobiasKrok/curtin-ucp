#include<stdio.h>
#include<stdlib.h>
#include"terminal.h"

int main()
{
	int i;
	char ch;

	system("clear");

	for(i = 0 ; i < 5 ; i++)
	{

		disableBuffer();
		scanf(" %c", &ch);
		enableBuffer();

		system("clear");
		printf("you entered -> %c\n", ch);
	}

	return 0;
}
