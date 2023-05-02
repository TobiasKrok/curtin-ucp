#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    void* data;
    struct node* next;
    struct node* previous;
} Node;

typedef struct ll {
    int size;
    Node* head;
    Node* tail;
} LinkedList;



LinkedList* createLinkedList(void);
void insertStart(LinkedList *list, void* data);
void* removeStart(LinkedList* list);
#endif