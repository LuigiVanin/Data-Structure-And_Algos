#include <stdio.h>
#include <stdlib.h>
#include "../include/arrayList.h"

struct ArrayList InitArrayList(int capacidade)
{
    struct ArrayList lista;
    lista.capacidade = capacidade;
    lista.tamanho = 0;
    lista.array = (int *)calloc(capacidade, sizeof(int));
    return lista;
}

void printList(struct ArrayList list)
{
    printf("[");
    for (int i = 0; i < list.tamanho; i++)
    {
        printf("%d, ", list.array[i]);
    }
    printf("]\n");
}

void double_size(struct ArrayList *list)
{
    list->capacidade = 2 * list->capacidade;
    list->array = (int *)realloc(list->array, list->capacidade * sizeof(int));
}

void push_item(struct ArrayList *list, int value)
{
    if (list->tamanho >= list->capacidade)
    {
        double_size(list);
    }
    list->array[list->tamanho] = value;
    list->tamanho++;
}

void update_item(struct ArrayList *list, int pos, int valor)
{
    if (pos > list->tamanho - 1)
        return;
    list->array[pos] = valor;
}

int remove_item(struct ArrayList *list)
{
    int res = list->array[list->tamanho - 1];
    list->tamanho--;
    return res;
}

void insert_at(struct ArrayList *list, int pos, int value)
{
    if (pos < 0 || pos > list->tamanho + 1)
    {
        return;
    }
    if (list->capacidade <= list->tamanho)
        double_size(list);

    for (int i = list->tamanho - 1; i >= pos; i--)
    {
        list->array[i + 1] = list->array[i];
        if (i == pos)
        {
            list->array[i] = value;
            list->tamanho++;
            return;
        }
    }
    return;
}

int remove_at(struct ArrayList *list, int pos)
{
    if (pos < 0 || pos > list->tamanho + 1)
    {
        return -1;
    }
    int res;
    for (int i = pos; i < list->tamanho - 1; i++)
    {
        if (i == pos)
            res = list->array[i];
        list->array[i] = list->array[i + 1];
    }
    list->tamanho--;
    return res;
}

void clear(struct ArrayList list)
{
    free(list.array);
}

/*
// HOW USE IT:

int main(){
    struct ArrayList teste = InitArrayList(10);
    printLista(teste);
    for(int i = 0; i < 11; i++){
        pushItem(&teste, i);
    }

    changeElement(&teste, 0, 13);
    printLista(teste);
    remove_item(&teste);
    printLista(teste);
    printf("capacidade: %d\ntamanho: %d\n", teste.capacidade, teste.tamanho);

    insertInPlace(&teste, 3, 1000);
    printLista(teste);
    return 0;
}
*/