//
// Created by htnek on 19/06/22.
//
#include "../include/insertionSort.h"
#include "../include/utils.h"
#include <stdio.h>

void insertion_sort(int *v, int size) {
    for(int i = 0; i < size; i++) {
        // printf("%d\n", v[i]);
        for(int j = i - 1 ;  j >= 0; j--) {
            if (v[j + 1] < v[j]) swap(v, j, j + 1);
            else break;
        } 

    }
}
