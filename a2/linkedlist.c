#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "macros.h"
#include "game.h"
#include "input.h"

LinkedList *ll_create(void)
{

    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));

    linkedList->head = NULL;
    linkedList->size = 0;
    linkedList->tail = NULL;

    return linkedList;
}

void ll_insert_start(LinkedList *list, void *data)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL)
    {
        node->previous = NULL;
        node->next = NULL;
        list->head = node;
        list->size = 1;

        list->tail = node;
        list->tail->next = NULL;
        list->tail->previous = NULL;
    }
    else
    {
        Node *prevHead = list->head;
        prevHead->previous = node;
        list->head = node;
        node->next = prevHead;
        list->size += 1;
        if (list->size == 2)
        {
            list->tail = prevHead;
            list->tail->previous = prevHead;
            list->tail->next = NULL;
        }
    }
}

Node *ll_remove_start(LinkedList *list)
{
    Node *removedNode = NULL;
    if (list != NULL && list->head != NULL)
    {
        removedNode = list->head;
        list->head = removedNode->next;
        list->head->previous = NULL;
        list->size -= 1;
    }
    return removedNode;
}

Node *ll_remove_last(LinkedList *list)
{
    Node *removedNode = NULL;

    if (list && list->head != NULL && list->tail != NULL)
    {
        removedNode = list->tail;
        if (removedNode->previous != NULL)
        {
            list->tail = removedNode->previous;
        }
        else
        {
            list->tail = NULL;
            list->head = NULL;
        }
        list->size -= 1;
    }
    return removedNode;
}

void ll_insert_last(LinkedList *list, void *data)
{
    if (list->head == NULL)
    {
        ll_insert_start(list, data);
    }
    else
    {
        Node *node = (Node *)malloc(sizeof(Node));
        Node *prevTail = list->tail;
        node->data = data;
        node->next = NULL;
        list->tail = node;
        node->previous = prevTail;
        prevTail->next = node;
        list->size += 1;
    }
}

int ll_is_empty(LinkedList *list)
{
    return list == NULL  || list->size == 0|| list->head == NULL;
}

