#include <stdio.h>
#include <stdlib.h>
#include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
// #include "include/arrayQueue.h"
// #include "include/linkedQueue.h"
// #include "include/bogo_search.h"
// #include "include/binary_search.h"
#include "include/graph_adj.h"
// #include "include/graph_matrix.h"
// #include "include/dfs.h"
#include "include/bfs.h"
// #include "include/insertionSort.h"
// #include "include/bogo_sort.h"
#include <time.h>
// #include "include/bubbleSort.h"
// #include "include/quicksort.h"

const int SIZE = 4;

int main() {   
    struct Graph graph = newGraph();
    graph.add_vertex(&graph); // label: 0
    graph.add_vertex(&graph); // label: 1
    graph.add_vertex(&graph); // label: 2
    graph.add_vertex(&graph); // label: 3
    graph.add_vertex(&graph); // label: 4


    graph.add_edge(&graph, 0, 1); // 0 -> 1 | 1 -> 0
    graph.add_edge(&graph, 0, 3); // 0 -> 3 | 3 -> 0
    graph.add_edge(&graph, 0, 0); // 0 -> 0
    // graph.add_edge(&graph, 3, 2); // 3 -> 2 | 2 -> 3
    graph.add_edge(&graph, 4, 2); // 4 -> 2 | 2 -> 4

    bool *visited = (bool*)calloc(graph.length, sizeof(bool));
    
    for (size_t i = 0; i < graph.length; i++) {
        printf("%d, ", visited[i]);
    }
    printf("\n");
    
    bfs(&graph, visited, 4);
    
    printf("\n");

    for (size_t i = 0; i < graph.length; i++) {
        printf("%d, ", visited[i]);
    }

    // int count = how_many_components_bfs(&graph);
    // printf("\n%d", count); // Should be 2;
    // printf("\n\n%d", vertex_connected_bfs(&graph, 0, 2)); // Should be false;
    // printf("\n%d\n", vertex_connected_bfs(&graph, 4, 2)); // Should be true;

    return 0;
}
