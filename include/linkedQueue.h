#define CPPALGOS_LINKEDQUEUE_H
#ifdef CPPALGOS_LINKEDQUEUE_H
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *next;
};

struct LinkedQueue
{
    struct Node *head;
    struct Node *tail;
    int length;
};

bool empty(struct LinkedQueue* queue);

void enqueue(struct LinkedQueue* queue, int val);

int desqueue(struct LinkedQueue* queue);

int head(struct LinkedQueue* queue);

void print_queue(struct LinkedQueue* queue) ;

#endif