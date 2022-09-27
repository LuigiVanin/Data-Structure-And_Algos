#include "../include/arrayQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct ArrayQueue initArrayQueue(int max){
    struct ArrayQueue queue;
    queue.len = 0;
    queue.max = max;
    queue.head = -1;
    queue.tail = -1;
    queue.array = (int*) calloc(queue.max, sizeof(int));
    return queue;
}


void enqueue(struct ArrayQueue* queue, int val) {
    if (( queue->len < queue->max )) {
        if(queue->len == 0){
            queue->head++;
        }
        queue->tail = (queue->tail + 1) % queue->max;
        queue->len++;
        queue->array[queue->tail] = val;
    }
    else{
        printf("a queue está cheia!\n");
    }
}


int desqueue(struct ArrayQueue* queue) {
    if ( queue == NULL || queue->len <= 0){
        return INT_MIN;
    }
    else{
        int tmp = queue->array[queue->head];
        for (int i = 0; i < queue->len - 1; i++ ) {
            queue->array[i] = queue->array[i + 1];
        }
        queue->len--;
        return tmp;
    }
}


int head(struct ArrayQueue* queue) {
    if ( queue == NULL || queue->len == 0){
        return INT_MIN;
    }
    else{
        return queue->array[queue->head];
    }
}


void print_queue(struct ArrayQueue lista) {
    printf("_\n");
    for (int i = 0; i < lista.max; i++) {
        printf("%d\n", lista.array[i]);
    }
    printf("_\n");
}

// #include "include/arrayQueue.h"

// int main(){
   
//     struct ArrayQueue queue = initArrayQueue(10);
//     printf("Alow\n");
//     enqueue(&queue, 10);
//     enqueue(&queue, 20);
//     enqueue(&queue, 220);
//     enqueue(&queue, 16);

//     // printf("%d\n", queue.array[queue.tail]);
//     // printf("%d\n", desqueue(&queue));
//     // printf("%d\n", desqueue(&queue));
//     // printf("%d\n", desqueue(&queue));
//     // printf("%d\n", desqueue(&queue));
//     // printf("%d\n", desqueue(&queue));
//     // printf("%d\n", desqueue(&queue));


    
//     print_queue(queue);

//     printf("\n%d - %d\n", desqueue(&queue), queue.len);
//     printf("\n%d - %d\n", desqueue(&queue), queue.len);
//     printf("\n%d - %d\n", desqueue(&queue), queue.len);
//     printf("\n%d - %d\n", desqueue(&queue), queue.len);
//     printf("\n%d - %d\n", desqueue(&queue), queue.len);
//     printf("\n%d - %d\n", desqueue(&queue), queue.len);

//     return 0;
// }