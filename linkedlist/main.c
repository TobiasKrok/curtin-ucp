#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{

    int i;
    LinkedList *linkedList = ll_create();
    for (i = 0; i < 10; i++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        ll_insert_last(linkedList, data);
    }
    ll_remove_last(linkedList);
    ll_remove_last(linkedList);

    printf("%d \n", linkedList->size);
    return 0;
}