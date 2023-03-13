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
#include "include/dfs.h"
// #include "include/insertionSort.h"
// #include "include/bogo_sort.h"
#include <time.h>
// #include "include/bubbleSort.h"
// #include "include/quicksort.h"

const int SIZE = 3;

int main() {
    struct Graph graph = newGraph();
    graph.add_vertex(&graph); // label: 0
    graph.add_vertex(&graph); // label: 1
    graph.add_vertex(&graph); // label: 2
    graph.add_vertex(&graph); // label: 3
    graph.add_vertex(&graph); // label: 4
    graph.add_vertex(&graph); // label: 5


    graph.add_edge(&graph, 0, 1); // 0 -> 1
    graph.add_edge(&graph, 0, 3); // 0 -> 3
    graph.add_edge(&graph, 0, 0); // 0 -> 0
    graph.add_edge(&graph, 3, 1); // 3 -> 1
    graph.add_edge(&graph, 5, 4); // 5 -> 4
    graph.add_edge(&graph, 4, 5); // 5 -> 4



    graph.print(&graph);

    printf(
        "number of components: %d\n",  
        how_many_components(&graph)
    );


    return 0;
}
