#include <stdio.h>
#include <stdlib.h>
// #include "include/arrayList.h"
// #include "include/linkedList.h"
#include "include/doublyLinkedList.h"

int main(){
   
   
    struct DoublyLinkedList test = initDoublyLinkedList();
    push_back(&test, 10);
    push_back(&test, 15);
    push_back(&test, 2);
    push_front(&test, 2);
    push_front(&test, 6);
    push_front(&test, 100);



    print_list(test);
    printf("%d", item_at(test, 2));
    // shift_list(&test);
    print_list(test);

    return 0;
}