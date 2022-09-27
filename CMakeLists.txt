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
               hashmap/HashMap.cpp include/HashMap.h 
               sorting/quicksort.c include/quicksort.h 
               sorting/bubbleSort.c sorting/insertionSort.c
               include/arrayQueue.h
               queue/arrayQueue.c
               include/linkedQueue.h
               queue/linkedQueue.c)

