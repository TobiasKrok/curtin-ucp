#include <stdio.h>

/*
Write a program to declare an integer variable, assign a value to it, and then create a pointer to that variable. Print the value of the variable using the pointer.
*/

void exercice_1()
{
    int x;
    x = 43;
    int *ptr = x;

    printf("%d", x);
}

int main()
{

    return 0
}