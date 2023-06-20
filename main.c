#include <stdio.h>
#include <stdlib.h>
#include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
// #include "include/arrayQueue.h"
// #include "include/linkedQueue.h"
// #include "include/bogo_search.h"
// #include "include/binary_search.h"
// #include "include/graph_adj.h"
#include "include/graph_matrix.h"
// #include "include/dfs.h"
// #include "include/insertionSort.h"
// #include "include/bogo_sort.h"
#include <time.h>
// #include "include/bubbleSort.h"
// #include "include/quicksort.h"

const int SIZE = 4;

int main() {   
    struct MatrixGraph graph = new_graph(SIZE);
    add_vertex(&graph, 0, 0, 2);
    add_vertex(&graph, 2, 1, 1);
    add_vertex(&graph, 0, 3, 12);
    add_vertex(&graph, 2, 3, 10);
    print_matrix_graph(graph);
    free_matrix_graph(graph);

    return 0;
}
