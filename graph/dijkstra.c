#include "../include/dijkstra.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

void starting_distances(int* distances, int length, int source) {
    for (int i = 0; i < length; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
}

void dijkstra(struct Graph *graph, int source) {
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    int *distances = (int *)calloc(graph->length, sizeof(int));

    starting_distances(distances, graph->length, source);

    printf("[");
    for (size_t i = 0; i < graph->length; i++) {
        printf("%d ", distances[i]);
    }
    printf("]\n");
}
