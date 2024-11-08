#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
    void *data;
    struct node *next;
    struct node *previous;
} Node;

typedef struct ll
{
    int size;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *ll_create(void);
void ll_insert_start(LinkedList *list, void *data);
void ll_insert_last(LinkedList *list, void *data);
Node *ll_remove_start(LinkedList *list);
Node *ll_remove_last(LinkedList *list);
#endif