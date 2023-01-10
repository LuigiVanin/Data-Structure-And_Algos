
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int id;
    struct node *next;
} node;

typedef struct graph
{
    int n;
    node **adj;
} graph;

graph *create_graph(int n);
void add_edge(graph *g, int u, int v);
int count_components(graph *g);
int is_in_list(int *list, int n, int node);

#endif