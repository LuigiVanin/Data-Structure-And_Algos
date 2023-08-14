#include "../include/selectionSort.h"
#include "../include/utils.h"

void selection_sort(int *v, int size)
{
    int min = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }

        swap(v, i, min);
    }
}