#include "order.h"
#include <stdio.h>

int main(){

/*     int bigger;
    int big;
    int small;
    big = 400;
    small = 200;
    bigger = 1000; */

    /* printf("big: %d \n", big);
    printf("small: %d \n", small);
    ascending2(&big, &small);

    printf("big: %d \n", big);
    printf("small: %d \n", small); */
/* 
    ascending3(&big, &small, &bigger);
    printf("bigger: %d \n", bigger);
        printf("big: %d \n", big);
    printf("small: %d \n", small);
 */

   int e[3][3] = {{10000,2,3}, {4,5,6}, {7,8,9}};

	/* 1 2 3 4 5 6 */

   int x[2][3];
   int** y = x;

   /*x[0][0] = &e[0][0];
   x[0][1] = &e[0][1];
   x[1][0] = &e[0][2];
   x[1][1] = &e[1][0];

   printf("%d \n", *(x[0][0]));*/



   /*
   
	|44	|7	|10	|66	|6	|77	|8	|13	|112|600|	|561|	|	|
	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24
	x	y	s					g	v   crazy	scores



	|	|	|5	|0	|0	|
	110	111	112	113	114	115	

	|	|44	|	|	|	| 78 |	|	|78	
	561	562	563	564	565	566	567	568	569


	|700|800|900
	600	601	602

	|44	|	|	
	700	701	702

	|	|	|	
	800	801	802

	|	|	|55	
	900	901	902


   */
	int* scores = (int*)malloc(sizeof(int) * 3 * 3);
	scores[( 0 * 3) + 1] = 44;
	int idx = (1*3) + 2;
	scores[idx] = 78;
	
	int** crazy = (int**)malloc(sizeof(int*) * 3); // 600
	crazy[0] = (int*)malloc(sizeof(int) * 3); // 700
	crazy[1] = (int*)malloc(sizeof(int) * 3); // 800
	crazy[2] = (int*)malloc(sizeof(int) * 3); // 900

	crazy[0][0] = 44;
	crazy[2][2] = 55;
	free(crazy);

	int whatthehell[3][3];
	whatthehell[0][0] = 11;

	int* notvalid1 = whatthehell;
	int** notvalid2 = whatthehell;

	int myData[5 * 4];









   int x = 2;
   int y = 7;
   int* s = &x;
   *s = 44;
   int g[] = {5,6,7,8};
   *g = 66;
   *(g+2) = 77;
   g[2] = 7;
   int* v = (int*)malloc(sizeof(int) * 3);
   v[0] = 5;

   //int scores[][] = 


    return 0;
}