
#ifndef GRAPH_ADJ_H
#define GRAPH_ADJ_H

#include "../include/arrayList.h"

struct Graph {
    int length;
    struct ArrayList *array;
    int capacity;
    // char** labels; -> para funcionar de maneira apropriada deve ser feito usando um array list de char*

    void (*add_edge)(struct Graph *self, int vertex, int value);
    void (*add_vertex)(struct Graph *self);
    void (*print)(struct Graph *self);
};

void __add_vertex(struct Graph *self );

void __add_edge(struct Graph *self, int vertex, int value );

void __resize_graph(struct Graph *self);

void __print_graph_adj(struct Graph *self);

struct Graph newGraph();

#endif