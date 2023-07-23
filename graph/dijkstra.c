#include "../include/dijkstra.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

void starting_distances(int *distances, int length, int source)
{
    for (int i = 0; i < length; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
}

void min_distance(struct Graph *graph, int *distances, int source)
{
    for (size_t i = 0; i < graph->array[source].tamanho; i++)
    {
        int target = graph->array[source].array[i];
        int cur_dist_weight = 1;
        int distance = distances[source] + cur_dist_weight;

        if (distance < distances[target])
        {
            distances[target] = distance;
        }
    }
}

int *dijkstra(struct Graph *graph, int source)
{
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    int *distances = (int *)calloc(graph->length, sizeof(int));

    starting_distances(distances, graph->length, source);
    for (size_t i = 0; i < graph->length; i++)
    {
        visited[i] = true;
        min_distance(graph, distances, i);
    }

    return distances;
}
