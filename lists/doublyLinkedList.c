#include "../include/doublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct DoublyLinkedList initDoublyLinkedList()
{
    struct DoublyLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    return list;
}

struct Node *newDoubleNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->next = NULL,
    node->prev = NULL,
    node->value = value;

    return node;
}

void push_back(struct DoublyLinkedList *list, int value)
{
    struct Node *newNode = newDoubleNode(value);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        list->length++;
        return;
    }
    struct Node *aux = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
    newNode->prev = aux;
    list->length++;
}

void push_front(struct DoublyLinkedList *list, int value)
{
    struct Node *newNode = newDoubleNode(value);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        list->length++;
        return;
    }

    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
    list->length++;
}

void print_list(struct DoublyLinkedList list)
{
    struct Node *aux = list.head;
    printf("[");
    while (aux != NULL)
    {
        printf(" %d,", aux->value);
        aux = aux->next;
    }
    printf(" ]\n");
}

int item_at(struct DoublyLinkedList list, int idx)
{
    if (idx >= list.length || idx < 0)
    {
        return NULL;
    }
    struct Node *aux;
    if (list.length / 2 < idx)
    {
        aux = list.tail;
        for (int i = list.length - 1; i > idx; i--)
        {
            aux = aux->prev;
            printf("%d\n", aux->value);
        }
    }
    else
    {
        aux = list.head;
        for (int i = 0; i < idx; i++)
        {
            aux = aux->next;
        }
    }

    return aux->value;
}

void shift_list(struct DoublyLinkedList *list)
{
    if (list->head == NULL || list->tail == NULL)
    {
        return;
    }
    struct Node *aux = list->head;
    list->head = list->head->next;
    free(aux);
    list->length--;
}

// HOW USE IT

// #include "include/doublyLinkedList.h"

// int main(){

//     struct DoublyLinkedList test = initDoublyLinkedList();
//     push_back(&test, 10);
//     push_back(&test, 15);
//     push_back(&test, 2);
//     push_front(&test, 2);
//     push_front(&test, 6);
//     push_front(&test, 100);

//     print_list(test);
//     printf("%d", item_at(test, 2));
//     // shift_list(&test);
//     print_list(test);

//     return 0;
// }