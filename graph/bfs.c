#include "../include/bfs.h"

void bfs(struct Graph *graph, bool *visited, int *count)
{
    
}

int how_many_components(struct Graph *graph)
{
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    int count = 0;

    bfs(graph, visited, &count);

    return count;
}