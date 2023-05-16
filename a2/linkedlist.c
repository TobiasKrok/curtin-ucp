#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "macros.h"

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
        /* Set the old head's previous to the new head*/
        prevHead->previous = node;
        /* Set the lists head to the new node*/
        list->head = node;
        /* Set the new head's next as the previous head node*/
        node->next = prevHead;
        list->size += 1;
        /* If the list size is two, then the previous head must be set as the tail */
        if (list->size == 2)
        {
            list->tail = prevHead;
            list->tail->next = NULL;
        }
    }
}

/**
 * Removes the first node from the linked list
 * @param list LinkedList to remove from
 * @returns pointer to the removed node
 * */

Node *ll_remove_start(LinkedList *list)
{
    Node *removedNode = NULL;

    if (list != NULL && list->head != NULL)
    {
        /* Store the removed node*/
        removedNode = list->head;
        /* Set the head to the next node*/
        list->head = removedNode->next;
        /* Set the new head's previous to null*/
        list->head->previous = NULL;
        list->size -= 1;
    }
    /* If the list is empty after we removed it, then we set everything to null*/
    if (list->size == 0)
    {
        list->tail = NULL;
        list->head = NULL;
    }
    return removedNode;
}

/**
 * Removes the last node from the linked list
 * @param list LinkedList to remove from
 * @returns pointer to the removed node
 * */
Node *ll_remove_last(LinkedList *list)
{
    Node *removedNode = NULL;

    if (list && list->head != NULL && list->tail != NULL)
    {
        /* Store the removed node*/
        removedNode = list->tail;
        /* Set the tail to the previous node if its not null*/
        if (removedNode->previous != NULL)
        {
            list->tail = removedNode->previous;
        }
        /* If the tail is null then the list is empty*/
        else
        {
            list->tail = NULL;
            list->head = NULL;
        }
        list->size -= 1;
    }
    return removedNode;
}

/**
 * Inserts a new node at the end of the linked list
 * @param list LinkedList to append to
 * @param data Data of the new linkedlist node
 * */
void ll_insert_last(LinkedList *list, void *data)
{
    /* If the list is empty then we insert at the start*/
    if (list->head == NULL)
    {
        ll_insert_start(list, data);
    }
    else
    {

        /* Store the previous tail*/
        Node *prevTail = list->tail;
        /* Initialize the node and set its properties*/
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        list->tail = node;
        /* Set the previous tail's next to the new tail*/
        node->previous = prevTail;
        prevTail->next = node;
        list->size += 1;
    }
}

/**
 * Checks if the linked list is empty
 * @param list LinkedList to check
 * @returns 1 if the list is empty, 0 otherwise
 * */
int ll_is_empty(LinkedList *list)
{
    return list == NULL || list->size == 0 || list->head == NULL;
}

/**
 * Iterates through the linked list and runs the callback function on each node
 * @param list LinkedList to iterate through
 * @param f Function to call on each node
 * */
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
