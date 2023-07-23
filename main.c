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
// #include "include/bfs.h"
// #include "include/insertionSort.h"
// #include "include/bogo_sort.h"
// #include <time.h>
// #include "include/bubbleSort.h"
// #include "include/quicksort.h"
#include "include/dijkstra.h"

const int SIZE = 4;

int main()
{
    struct Graph graph = newGraph();
    graph.add_vertex(&graph); // label: 0
    graph.add_vertex(&graph); // label: 1
    graph.add_vertex(&graph); // label: 2
    graph.add_vertex(&graph); // label: 3
    graph.add_vertex(&graph); // label: 4
    graph.add_vertex(&graph); // label: 5
    graph.add_vertex(&graph); // label: 6

    graph.add_edge(&graph, 0, 1);
    graph.add_edge(&graph, 1, 3);
    graph.add_edge(&graph, 1, 5);
    graph.add_edge(&graph, 3, 4);
    graph.add_edge(&graph, 2, 5);
    graph.add_edge(&graph, 3, 2);
    graph.add_edge(&graph, 0, 2);
    graph.add_edge(&graph, 2, 4);
    graph.add_edge(&graph, 4, 6);

    int *distances = dijkstra(&graph, 0);
    printf("[");
    for (size_t i = 0; i < graph.length; i++)
    {
        printf("%d ", distances[i]);
    }
    printf("]\n");

    return 0;
}
