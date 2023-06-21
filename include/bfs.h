#ifndef BFS_H
#define BFS_H
#include "../include/graph_adj.h"
#include <stdlib.h>
#include <stdbool.h>

void bfs(struct Graph *graph, bool *visited, int index);

// int reach_from_pos_0(struct Graph *graph);
bool vertex_connected_bfs(struct Graph *graph, int v1, int v2);

int how_many_components_bfs(struct Graph *graph);

#endif
