#define CPPALGOS_LINKEDLIST_H 
#ifdef CPPALGOS_LINKEDLIST_H

struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
    int length;
};


struct DoublyLinkedList initDoublyLinkedList();

struct Node* newDoubleNode(int value);

void push_back(struct DoublyLinkedList *list, int value);
void push_front(struct DoublyLinkedList *list, int value);
void print_list(struct DoublyLinkedList list);
int item_at(struct DoublyLinkedList list, int idx);
void shift_list(struct DoublyLinkedList *list) ;

#endif
