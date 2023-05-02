#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

    int i;
    LinkedList* linkedList = createLinkedList();
    for(i = 0; i < 10; i ++) {
        int* data = (int*)malloc(sizeof(int));
        *data = i;
        insertStart(linkedList, data);
    }
    removeStart(linkedList);
    removeStart(linkedList);
    removeStart(linkedList);

    printf("%d \n", linkedList->size);
    return 0;
}