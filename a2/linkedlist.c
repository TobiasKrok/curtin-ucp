#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "macros.h"
#include "game.h"
#include "input.h"

/**
 * Creates and initializes a LinkedList
 * @returns pointer to a LinkedList struct
*/

LinkedList *ll_create(void)
{

    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));

    linkedList->head = NULL;
    linkedList->size = 0;
    linkedList->tail = NULL;

    return linkedList;
}

/** 
 * Inserts a new node at the head of the linked list
 * @param list LinkedList to append to
 * @param data Data of the new linkedlist node 
 * */
void ll_insert_start(LinkedList *list, void *data)
{
    /* Initialize the node*/
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    /* If the head is null then the list is empty*/
    if (list->head == NULL)
    {
        /* Th first node will have no next and previous (as the linkedlist only contains 1 element) */
        node->previous = NULL;
        node->next = NULL;
        list->head = node;
        list->size = 1;

        /* Also set the tail of the node to the first node as it is both the head and the tail*/
        list->tail = node;
        list->tail->next = NULL;
        list->tail->previous = NULL;
    }
    else
    {
        /* Store the previous head*/
        Node *prevHead = list->head;
        /* Set the old heads' previous to the */
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
    return list == NULL || list->size == 0 || list->head == NULL;
}
void ll_iterate(LinkedList *list, void (*f)(Node *node))
{
    Node *currentNode = list->head;
    Node *nextNode;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        f(currentNode);
        currentNode = nextNode;
    }
}
