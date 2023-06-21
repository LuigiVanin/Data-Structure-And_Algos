#include "../include/bfs.h"
#include "../include/linkedQueue.h"
#include <stdbool.h>

void bfs(struct Graph *graph, bool *visited, int index) {
    struct LinkedQueue queue = initLinkedQueue();
    linked_enqueue(&queue, index);
        while(!empty(&queue)) {
        int head = linked_desqueue(&queue);
        if(!visited[head]) visited[head] = true;
        for (size_t i = 0; i < graph->array[head].tamanho; i++) {
            if (!visited[graph->array[head].array[i]]){
                linked_enqueue(&queue, graph->array[head].array[i]);
            }
        }
    }
}

int how_many_components_bfs(struct Graph *graph) 
{
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    int count = 0;
    for(int i = 0; i < graph->length; i++) {
        if (!visited[i]) {
            count++;
            bfs(graph, visited, i);
        }
    }

    free(visited);
    return count;   
}

bool vertex_connected_bfs(struct Graph *graph, int v1, int v2) 
{
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    bfs(graph, visited, v1);

    if  (!visited[v2]) {
        return false;
    }
    return true;
}
