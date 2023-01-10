#include "../include/selectionSort.h"

void selection_sort(int* v, int size){
    int min = 0;
    for(int i = 0; i < size-1; i++) {
        min = i;
        for(int j = i+1; j < size; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }

        swap_p(v, i, min);
    }
}

void swap_p(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}