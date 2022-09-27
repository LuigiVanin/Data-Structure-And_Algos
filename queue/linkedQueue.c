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

struct Node* newQueueNode(int valor) {
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

void linked_enqueue(struct LinkedQueue* queue, int val) {
    if( queue == NULL || queue->length == 0){
        *queue = initLinkedQueue();
        queue->head = newQueueNode(val);
        queue->tail = queue->head;
    }
    else{
        struct Node* cabeca = queue->tail;
        cabeca->next = newQueueNode(val);
        cabeca = cabeca->next;
        queue->tail = cabeca;
    }
    queue->length++;
}

int linked_desqueue(struct LinkedQueue* queue) {
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

int peak(struct LinkedQueue* queue) {
    if ( queue == NULL || queue->length == 0){
        return INT_MIN;
    }
    else{
        return queue->head->val;
    }
}

void print_linked_queue(struct LinkedQueue queue) {
    if (queue.head != NULL) {
        struct Node* aux = queue.head;
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

// int main(){
//     struct LinkedQueue queue = initLinkedQueue();
//     printf("Alow\n");
//     linked_enqueue(&queue, 10);
//     linked_enqueue(&queue, 15);
//     linked_enqueue(&queue, 30);
//     linked_enqueue(&queue, 90);
//     printf("%d\n", peak(&queue));
//     print_linked_queue(queue);
//     linked_desqueue(&queue);
//     linked_desqueue(&queue);
//     linked_desqueue(&queue);
//     linked_desqueue(&queue);
//     print_linked_queue(queue);
//     return 0;
// }