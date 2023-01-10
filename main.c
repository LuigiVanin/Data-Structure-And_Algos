#include <stdio.h>
#include <stdlib.h>
// #include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
// #include "include/arrayQueue.h"
// #include "include/linkedQueue.h"
// #include "include/bogo_search.h"
// #include "include/binary_search.h"
// #include "include/insertionSort.h"
#include "include/bogo_sort.h"
#include <time.h>
// #include "include/selectionSort.h"

const int SIZE = 3;

int main(){
    int *v = (int*) calloc(SIZE, SIZE*sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        v[i] = i;
    }

    // populate v array with random numbers
    for (int i = 0; i < SIZE; i++) {
        v[i] = rand() % 100;
    }

    printf("[\n\t");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", v[i]);
    }
    printf("\n]\n");

    
    bogo_sort(v, SIZE);
    printf("[\n\t");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", v[i]);
    }
    printf("\n]");
    return 0;
}