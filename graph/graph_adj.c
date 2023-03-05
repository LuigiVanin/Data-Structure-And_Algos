#include "../include/graph_adj.h"
#include <stdlib.h>
#include <stdio.h>

void __resize_graph(struct Graph *graph ) {
        graph->capacity = 2*graph->capacity;
        graph->array = (struct ArrayList*) realloc(graph->array, graph->capacity * sizeof(struct ArrayList*));
}


void __add_edge(struct Graph *self, int vertex, int value ) {
    if (self->length - 1 < vertex) {
        printf("Não há vertice com esse label %d", vertex);
        return;
    
    };
    if (self->length - 1 < value) {
        printf(
            "Não há vertice com esse label %d - logo, não é possível se conectar\n ",
             vertex
        );
        return;
    }
    push_item(&self->array[vertex], value);
    printf("add_edge %d -> %d\n", vertex, value);
}

void __add_vertex(struct Graph *self ) {
    if (self->length == self->capacity) {
        // caso não funcione voltar para a alternativa anterior
        __resize_graph(self);
    }
    self->array[self->length] = InitArrayList(8);
    self->length++;
    printf("add_vertex %d\n", self->length - 1);
}

struct Graph newGraph() {
    struct Graph g;
    g.length = 0;
    g.capacity = 8;
    g.array = (struct ArrayList*) calloc(g.capacity, sizeof(struct ArrayList));
    g.add_edge = __add_edge;
    g.add_vertex = __add_vertex;
    return g;
}

// int main() {
//     struct Graph graph = newGraph();
//     graph.add_vertex(&graph); // label: 0
//     graph.add_vertex(&graph); // label: 1
//     graph.add_vertex(&graph); // label: 2
//     graph.add_vertex(&graph); // label: 3

//     graph.add_edge(&graph, 0, 1); // 0 -> 1
//     graph.add_edge(&graph, 0, 3); // 0 -> 3
//     graph.add_edge(&graph, 0, 0); // 0 -> 0

//     return 0;
// }