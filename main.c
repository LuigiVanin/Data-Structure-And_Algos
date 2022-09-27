#include <stdio.h>
#include <stdlib.h>
// #include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
// #include "include/arrayQueue.h"
// #include "include/linkedQueue.h"
#include "include/bogo_search.h"

int main(){
    int *v = (int*) calloc(15, 15*sizeof(int));
    for (int i = 0; i < 15; i++) {
        v[i] = i;
    }

    printf("%d\n", bogo_search(v, 15, 6, 100000));
    return 0;
}