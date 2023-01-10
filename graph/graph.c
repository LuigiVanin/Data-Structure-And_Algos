#include "../include/graph.h"
#include <stdlib.h>

graph *create_graph(int n)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = n;
    g->adj = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
    {
        g->adj[i] = NULL;
    }
    return g;
}

void add_edge(graph *g, int u, int v)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->id = v;
    new_node->next = g->adj[u];
    g->adj[u] = new_node;
}

int is_in_list(int *list, int n, int node)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i] == node)
        {
            return 1;
        }
    }
    return 0;
}

int count_components(graph *g)
{
    int *visited = (int *)malloc(g->n * sizeof(int));
    int *queue = (int *)malloc(g->n * sizeof(int));
    int count = 0;
    for (int i = 0; i < g->n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < g->n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            int head = 0;
            int tail = 0;
            queue[tail++] = i;
            visited[i] = 1;
            while (head < tail)
            {
                int u = queue[head++];
                for (node *v = g->adj[u]; v != NULL; v = v->next)
                {
                    if (visited[v->id] == 0)
                    {
                        queue[tail++] = v->id;
                        visited[v->id] = 1;
                    }
                }
            }
        }
    }
    return count;
}