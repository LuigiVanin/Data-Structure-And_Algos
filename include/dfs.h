
#ifndef DFS_H
#define DFS_H
#include "../include/graph_adj.h"
#include <stdlib.h>
#include <stdbool.h>

void dfs(struct Graph *graph, bool *visited, int index);

int reach_from_pos_0(struct Graph *graph);

int how_many_components(struct Graph *graph);

bool vertex_connected(struct Graph *graph, int v1, int v2);


#endif
