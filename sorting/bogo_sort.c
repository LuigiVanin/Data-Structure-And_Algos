#include "../include/bogo_sort.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


void bogo_sort(int *array, int size) {
    while (!is_sorted(array, size)) {

        shuffle(array, size);
    }
}

bool is_sorted(int *array, int size) {
    for(int i = 0; i < size - 1 ; i++) {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}

void shuffle(int *array, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}