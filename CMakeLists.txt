cmake_minimum_required(VERSION 3.16.0)
project(cpp-algo)

include_directories(cpp-algo)

add_executable(cpp-algo main.c 
               include/arrayList.h 
               lists/arrayList.c 
               include/linkedList.h 
               lists/linkedList.c 
               include/doublyLinkedList.h 
               lists/doublyLinkedList.c 
               sorting/quicksort.c include/quicksort.h 
               sorting/bubbleSort.c sorting/insertionSort.c
               include/insertionSort.h
               include/arrayQueue.h
               queue/arrayQueue.c
               include/linkedQueue.h
               queue/linkedQueue.c
               include/linear_search.h
               search/linear_search.c
               include/bogo_search.h
               search/bogo_search.c
               include/binary_search.h
               search/binary_search.c
               sorting/selectionSort.c
               include/selectionSort.h
               include/bogo_sort.h
               sorting/bogo_sort.c
               include/graph_adj.h
               graph/graph_adj.c
               include/utils.h
               utils/array.c
               include/dfs.h
               graph/dfs.c)

