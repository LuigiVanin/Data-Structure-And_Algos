#include "../include/linkedQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct LinkedQueue initLinkedQueue() {
    struct LinkedQueue queue;
    queue.length = 0;
    queue.tail = NULL;
    queue.head = NULL;
    return queue;
}

struct Node* newNode(int valor) {
    struct Node* cabeca = (struct Node*) malloc(sizeof(struct Node));
    cabeca->val = valor;
    cabeca->next = NULL;
    return cabeca;
}

bool empty(struct LinkedQueue* queue) {
    if( queue == NULL || queue->length == 0){
        return true;
    }
    else{
        return false;
    }
}

//se a queue estiver nula, instancie a queue
//por causa da possibilidade de instanciacao usamos struct LinkedQueue**
void enqueue(struct LinkedQueue* queue, int val) {
    if( queue == NULL || queue->length == 0){
        *queue = initLinkedQueue();
        queue->head = newNode(val);
        queue->tail = queue->head;
    }
    else{
        struct Node* cabeca = queue->tail;
        cabeca->next = newNode(val);
        cabeca = cabeca->next;
        queue->tail = cabeca;
    }
    queue->length++;
}

//retorne a constante INT_MIN se a queue for nula ou vazia
//lembrem de desalocar o nó removido (free)
int desqueue(struct LinkedQueue* queue) {
    if ( queue == NULL || queue->length == 0){
        return INT_MIN;
    }
    else{
        struct Node* aux = queue->head;
        int tmp = aux->val;
        if(aux->next != NULL){
            aux = aux->next;
            free(queue->head);
            queue->head = aux;
        }
        else{
            queue->head = NULL;
            queue->tail = NULL;
            free(queue->head);
        }
        queue->length--;
        return tmp;
    }
}

//retorne a constante INT_MIN se a queue for nula ou vazia
int head(struct LinkedQueue* queue) {
    if ( queue == NULL || queue->length == 0){
        return INT_MIN;
    }
    else{
        return queue->head->val;
    }
}

void print_queue(struct LinkedQueue* queue) {
    //usamos o aux para percorrer a lista
    if (queue->head != NULL) {
        struct Node* aux = queue->head;
        //navega partindo da cabeça até chegar NULL
        printf("_\n");
        do {
            printf("%d", aux->val);
            aux = aux->next;
            if (aux != NULL) {
                printf("\n ");
            }
        } while (aux != NULL);
        printf("\n_\n");
    }
    else {
        printf("A lista está vazia!");
    }
}
