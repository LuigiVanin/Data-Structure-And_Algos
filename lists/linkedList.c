#include "../include/linkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkedList initLinkedList()
{
    struct LinkedList list;
    list.head = NULL;
    list.tamanho = 0;
    return list;
}

struct Node *newNode(int value)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node *));
    node->value = value;
    node->next = NULL;
    return node;
}

void push(struct LinkedList *list, int value)
{
    if (list->head == NULL)
    {
        list->head = newNode(value);
        list->tamanho++;
        return;
    }

    struct Node *aux;
    aux = (struct Node *)malloc(sizeof(struct Node *));
    aux = list->head;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = newNode(value);
    list->tamanho++;
    return;
}

int getElement(struct LinkedList list, int index)
{
    if (index >= list.tamanho && index < 0)
    {
        printf("Erro! index deve estar maior que 0 e menor que %d", list.tamanho);
        return NULL;
    }
    struct Node *aux;
    aux = (struct Node *)malloc(sizeof(struct Node *));
    aux = list.head;
    for (int i = 0; i < index; i++)
    {
        aux = aux->next;
    }
    return aux->value;
}

void shift(struct LinkedList *list, int value)
{
    struct Node *head = newNode(value);
    head->next = list->head;
    list->head = head;
    list->tamanho++;
    printf("%d\n", head->value);
}

void insertAt(struct LinkedList *list, int value, int pos)
{
    if (list->tamanho <= pos && pos < 0)
    {
        printf("Index extrapola o tamanho da lista");
        return NULL;
    }
    if (pos == 0)
        return shift(list, value);
    struct Node *aux = list->head;
    struct Node *new = newNode(value);
    for (int i = 0; i < pos - 1; i++)
    {
        if (aux->next != NULL)
            aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
    list->tamanho++;
}

int deleteAt(struct LinkedList *list, int pos)
{
    if (list->tamanho <= pos && pos < 0)
    {
        printf("Index extrapola o tamanho da lista");
        return NULL;
    }
    int ans;
    if (pos == 0)
    {
        ans = list->head->value;
        list->head = list->head->next;
        return ans;
    }
    struct Node *aux = list->head;
    struct Node *tmp;
    for (int i = 0; i < pos; i++)
    {
        if (aux != NULL)
            tmp = aux;
        aux = aux->next;
    }
    tmp->next = aux->next;
    ans = aux->value;
    list->tamanho--;
    free(aux);
    return ans;
}

void printLinkedList(struct LinkedList list)
{
    struct Node *aux = list.head;
    printf("[");
    for (int i = 0; i < list.tamanho; i++)
    {
        if (aux != NULL)
        {
            printf("%d, ", aux->value);
            aux = aux->next;
        }
    }
    printf("]\n");
}
/*
int main(){
    struct LinkedList list = initLinkedList();

    printf("%d\n", list.tamanho);

    push(&list, 10);
    push(&list, 15);
    printf("tamanaho: %d\n", list.tamanho);

    printf("%d\n", getElement(list, 1));

    shift(&list, 109);
    printf("tamanaho: %d\n", list.tamanho);
    printf("%d\n", getElement(list, 1));

    insertAt(&list, 17, 0);
    printf("%d\n", getElement(list, 2));

    printf("delete at: %d\n", deleteAt(&list, 3));

    printLinkedList(list);
    return 0;
}
*/