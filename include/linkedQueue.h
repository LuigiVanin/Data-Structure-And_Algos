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

struct LinkedQueue initLinkedQueue();

struct Node *newQueueNode(int valor);

bool empty(struct LinkedQueue *queue);

void linked_enqueue(struct LinkedQueue *queue, int val);

int linked_desqueue(struct LinkedQueue *queue);

int peak(struct LinkedQueue *queue);

void print_linked_queue(struct LinkedQueue queue);

#endif