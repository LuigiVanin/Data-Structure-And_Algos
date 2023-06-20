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
void print_matrix_graph(struct MatrixGraph g);
void free_matrix_graph(struct MatrixGraph g);
void add_vertex(struct MatrixGraph *g, int i, int j, int value);

#endif
