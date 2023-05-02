#include "linkedlist.h"
#include <stdlib.h>

LinkedList* createLinkedList(void) {


    LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));

    linkedList->head = NULL;
    linkedList->size = 0;
    linkedList->tail = NULL;

    return linkedList;
} 


void insertStart(LinkedList *list, void* data) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL) {
        node->previous = NULL;
        node->next = NULL;
        list->head = node;
        list->size = 1;

        list->tail = node;
        list->tail->next = NULL;
        list->tail->previous = NULL;

    } else {
        Node *prevHead = list->head;
        prevHead->previous = node;
        list->head = node;
        node->next = prevHead;
        list->size += 1;
        if(list->size == 2) {
            list->tail = prevHead;
            list->tail->previous = prevHead;
            list->tail->next = NULL;
        }
    }
}

void* removeStart(LinkedList* list) {
    Node* removedNode = NULL;
    if(list != NULL && list->head != NULL) {
        removedNode = list->head;
        list->head = removedNode->next;
        list->head->previous = NULL;
        list->size -= 1;

    }
    return removedNode;
}

void insertLast(LinkedList* list, void* data) {
    if(list->head == NULL) {
        insertStart(list, data);
    } else {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->next == NULL;
        Node *prevTail = list->tail;
        list->tail = node;
        node->previous = prevTail;
        prevTail->next = node;
        list->size += 1;
    }

}
