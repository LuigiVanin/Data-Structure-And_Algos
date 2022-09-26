#include "../include/arrayQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct ArrayQueue initArrayQueue(int length){
    struct ArrayQueue queue;
    queue.max = 0;
    queue.length = length;
    queue.head = -1;
    queue.tail = -1;
    queue.array = (int*) calloc(queue.length, sizeof(int));
    return queue;
}

//se a queue estiver nula, instancie a queue com length 10
//por causa da possibilidade de instanciacao usamos struct ArrayQueue**
//se a queue encher, simplesmente não enfileire
void enqueue(struct ArrayQueue** queue, int val) {
    if ( (*queue) == NULL ){
        struct ArrayQueue aux;
        (*queue) = &aux;
        printf("none?\n");
        enqueue(queue, val);
    }
    else if (( (*queue)->max < (*queue)->length )) {
        if((*queue)->max == 0){
            (*queue)->head++;
        }
        (*queue)->tail = ((*queue)->tail + 1) % (*queue)->length;
        (*queue)->max++;
        (*queue)->array[(*queue)->tail] = val;
    }
    else{
        printf("a queue está cheia!\n");
    }
}

//retorne a constante INT_MIN se a queue for nula ou vazia
int desqueue(struct ArrayQueue* queue) {
    if ( queue == NULL || queue->max <= 0){
        return INT_MIN;
    }
    else{
        int tmp = queue->array[queue->head];
        queue->head = (queue->head + 1) % queue->length;
        queue->max--;
        return tmp;
    }
}

//retorne a constante INT_MIN se a queue for nula ou vazia
int head(struct ArrayQueue* queue) {
    if ( queue == NULL || queue->max == 0){
        return INT_MIN;
    }
    else{
        return queue->array[queue->head];
    }
}

void print_queue(struct ArrayQueue* lista) {
    printf("_\n");
    for (int i = 0; i < lista->length; i++) {
        printf("%d\n", lista->array[i]);
    }
    printf("_\n");
}