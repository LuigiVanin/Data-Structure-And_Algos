#ifndef CPP_GRAPH_MATRIX_H
#define CPP_GRAPH_MATRIX_H

struct MatrixGraph
{
    int n;
    int m;
    int **edges;

    // struct MatrixGraph (*new_graph)(int n);
};

struct MatrixGraph new_graph(int n);

#endif
