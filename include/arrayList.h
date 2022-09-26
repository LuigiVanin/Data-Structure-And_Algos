#ifndef CPPALGOS_ARRAYLIST_H
#define CPPALGOS_ARRAYLIST_H

struct ArrayList {
    int capacidade;
    int tamanho;
    int *array;
} array_list;

struct ArrayList InitArrayList(int capacidade);

void printLista(struct ArrayList list);

void push_item(struct ArrayList *list, int value);

void double_size(struct ArrayList *list);

void change_item(struct ArrayList *list, int pos,int valor);

int remove_item(struct ArrayList *list);

void insert_at(struct ArrayList *list, int pos, int value);

int remove_at(struct ArrayList *list, int pos);

void clear(struct ArrayList list);

#endif