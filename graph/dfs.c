#include "../include/dfs.h"
#include "../include/utils.h"
#include <stdbool.h>

void dfs(struct Graph *graph, bool *visited, int index)
{
    visited[index] = true;
    for (int i = 0; i < graph->array[index].tamanho; i++) {
        if (!visited[graph->array[index].array[i]]) {
            dfs(graph, visited, graph->array[index].array[i]);
        }
    }
}

void dfsStack(struct Graph *graph, bool *visited, int index) {}

int reach_from_pos_0(struct Graph *graph)
{
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    // int count = 0;
    dfs(graph, visited, 0);
    print_boolean_areray(visited, graph->length);
    free(visited);
    // return count;
    return 1;
}

// NOTE: Para grafo adirecionais uma simples dfs com um array de vértices visitados é o suficiente
// para concluir a atividade, mas para casos de grafos direcionais existem outro algoritmos
// https://en.wikipedia.org/wiki/Strongly_connected_component - não irei entrar nisso
int how_many_components(struct Graph *graph) {
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    int count = 0;
    for(int i = 0; i < graph->length; i++) {
        if (!visited[i]) {
            count++;
            dfs(graph, visited, i);
        }
    }

    free(visited);
    return count;   
}

// NOTE: novamente, essa  solução para um caso de grafo adirecinal, para
// para grafos direcionais o buraco é mais embaixo - não iremos entrar nisso
bool vertex_connected(struct Graph *graph, int v1, int v2) {
    bool *visited = (bool *)calloc(graph->length, sizeof(bool));
    dfs(graph, visited, v1);
    if  (visited[v2]) {
        return false;
    }
    return true;
}

// int main() {
//     struct Graph graph = newGraph();
//     graph.add_vertex(&graph); // label: 0
//     graph.add_vertex(&graph); // label: 1
//     graph.add_vertex(&graph); // label: 2
//     graph.add_vertex(&graph); // label: 3
//     graph.add_vertex(&graph); // label: 4
//     graph.add_vertex(&graph); // label: 5

//     graph.add_edge(&graph, 0, 1); // 0 -> 1
//     graph.add_edge(&graph, 0, 3); // 0 -> 3
//     graph.add_edge(&graph, 0, 0); // 0 -> 0
//     graph.add_edge(&graph, 3, 1); // 3 -> 1
//     graph.add_edge(&graph, 5, 4); // 5 -> 4
//     graph.add_edge(&graph, 4, 5); // 5 -> 4
//     graph.print(&graph);

//     printf(
//         "number of components: %d\n",  
//         how_many_components(&graph)
//     );
//     return 0;
// }

