#include "../include/graph_matrix.h"
#include <stdio.h>
#include <stdlib.h>

// It good to know that there is also the implementation of the dfs and bfs for graph matrix.
struct MatrixGraph new_graph(int n)
{
    struct MatrixGraph g;
    g.m = n;
    g.n = n;
    g.edges = (int **)malloc(sizeof(int *) * g.n);
    for (int i = 0; i < n; i++)
    {
        g.edges[i] = (int *)calloc(n, sizeof(int));
    }

    return g;
}

void free_matrix_graph(struct MatrixGraph g)
{
    for (size_t i = 0; i < g.n; i++)
    {
        free(g.edges[i]);
    }
    free(g.edges);
}

void add_vertex(struct MatrixGraph *g, int i, int j, int value)
{
    g->edges[i][j] = value;
    g->edges[j][i] = value;
}

void print_matrix_graph(struct MatrixGraph g)
{
    printf("[ ");
    for (size_t i = 0; i < g.n; i++)
    {
        printf("\n\t[ ");
        for (size_t j = 0; j < g.m; j++)
        {
            printf("%d, ", g.edges[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}

// int main() {
//     struct MatrixGraph graph = new_graph(SIZE);
//     add_vertex(&graph, 0, 0, 2);
//     add_vertex(&graph, 2, 1, 1);
//     add_vertex(&graph, 0, 3, 12);
//     add_vertex(&graph, 2, 3, 10);
//     print_matrix_graph(graph);
//     free_matrix_graph(graph);

//     return 0;
// }