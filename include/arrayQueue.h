#define CPPALGOS_ARRAYQuEUE_H
#ifdef CPPALGOS_ARRAYQuEUE_H

struct ArrayQueue
{
    int head;
    int tail;
    int *array;
    int length; // tam do array
    int max;    // max de qeue no array
};

struct ArrayQueue initArrayQueue(int length);
void enqueue(struct ArrayQueue** queue, int val);
int desqueue(struct ArrayQueue* queue);
int head(struct ArrayQueue* queue);


#endif