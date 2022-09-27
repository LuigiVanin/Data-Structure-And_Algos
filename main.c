#include <stdio.h>
#include <stdlib.h>
// #include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
#include "include/arrayQueue.h"

int main(){
   
    struct ArrayQueue queue = initArrayQueue(10);
    printf("Alow\n");
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 220);
    enqueue(&queue, 16);

    // printf("%d\n", queue.array[queue.tail]);
    // printf("%d\n", desqueue(&queue));
    // printf("%d\n", desqueue(&queue));
    // printf("%d\n", desqueue(&queue));
    // printf("%d\n", desqueue(&queue));
    // printf("%d\n", desqueue(&queue));
    // printf("%d\n", desqueue(&queue));


    
    print_queue(queue);

    printf("\n%d - %d\n", desqueue(&queue), queue.len);
    printf("\n%d - %d\n", desqueue(&queue), queue.len);
    printf("\n%d - %d\n", desqueue(&queue), queue.len);
    printf("\n%d - %d\n", desqueue(&queue), queue.len);
    printf("\n%d - %d\n", desqueue(&queue), queue.len);
    printf("\n%d - %d\n", desqueue(&queue), queue.len);



    return 0;
}