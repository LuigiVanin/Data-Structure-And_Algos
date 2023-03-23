#include "../include/graph_matrix.h"
#include <stdlib.h>

struct MatrixGraph new_graph(int n) {
    struct MatrixGraph g;
    g.m = n;
    g.n = n;
    g.edges = (int**)malloc( sizeof(int*) * g.n);
    for(int i = 0; i < n; i++) {
        g.edges[i] = (int*)calloc(n, sizeof(int));
    }

    return g;
}
