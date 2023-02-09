//
// Created by htnek on 19/06/22.
//
#include "../include/quicksort.h"
#include "../include/utils.h"

void quick_sort(int* v, int ini, int fim){
    if(fim>ini){
        int indexPivo = partition(v,ini,fim);
        quick_sort(v,ini,indexPivo-1);
        quick_sort(v,indexPivo+1,fim);
    }
}


int partition(int* v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v,i,pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,fim);
    return pIndex;
}