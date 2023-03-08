
#ifndef BFS_H
#define BFS_H
#include "../include/graph_adj.h"
#include <stdlib.h>
#include <stdbool.h>

void bfs(struct Graph *graph, bool *visited, int *count);

int how_many_components(struct Graph *graph);

#endif
