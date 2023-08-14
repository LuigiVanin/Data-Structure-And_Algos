#include "../include/utils.h"
#include <time.h>

void swap(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void shuffle(int *array, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool is_sorted(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void print_boolean_areray(bool *array, int len)
{
    printf("\n[");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}
