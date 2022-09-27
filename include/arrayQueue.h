#define CPPALGOS_ARRAYQuEUE_H
#ifdef CPPALGOS_ARRAYQuEUE_H

struct ArrayQueue
{
    int head;
    int tail;
    int *array;
    int max; // tam do array
    int len;    // max de qeue no array
};

struct ArrayQueue initArrayQueue(int max);
void enqueue(struct ArrayQueue* queue, int val);
int desqueue(struct ArrayQueue* queue);
int head(struct ArrayQueue* queue);
void print_queue(struct ArrayQueue);


#endif