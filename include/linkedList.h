#define CPPALGOS_LINKEDLIST_H
#ifdef CPPALGOS_LINKEDLIST_H

#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct LinkedList
{
    int tamanho;
    struct Node *head;
};

struct LinkedList initLinkedList();

struct Node *newNode(int value);

void push(struct LinkedList *list, int value);

int getElement(struct LinkedList list, int index);

void shift(struct LinkedList *list, int value);

void insertAt(struct LinkedList *list, int value, int pos);

void printLinkedList(struct LinkedList);

int deleteAt(struct LinkedList *list, int pos);

#endif