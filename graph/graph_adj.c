#include "../include/graph_adj.h"
#include <stdlib.h>
#include <stdio.h>

void __resize_graph(struct Graph *self ) {
        self->capacity = 2*self->capacity;
        self->array = (struct ArrayList*) realloc(self->array, self->capacity * sizeof(struct ArrayList*));
}

// TODO: This should be the representation of a undirectional graph
// so when adding a edgem the edge in question should be present on both vertex
// in other words, you have to push on both vertexs
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
        __resize_graph(self);
    }
    self->array[self->length] = InitArrayList(8);
    self->length++;
    printf("add_vertex %d\n", self->length - 1);
}

void __print_graph_adj(struct Graph *self) {
    for (int i = 0; i < self->length; i++) {
        struct ArrayList item = self->array[i];
        printf("- Vertex %d:\n", i);
        if (item.tamanho == 0) {
            printf("\tEMPTY\n");
            continue;;
        }
        for (int j = 0; j < item.tamanho; j++) {
            printf("\t --> %d\n", item.array[j]);
        }
    }
    return;
}   
struct Graph newGraph() {
    struct Graph g;
    g.length = 0;
    g.capacity = 8;
    g.array = (struct ArrayList*) calloc(g.capacity, sizeof(struct ArrayList));
    g.add_edge = __add_edge;
    g.add_vertex = __add_vertex;
    g.print = __print_graph_adj;
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