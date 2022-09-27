#ifndef GTEST_LISTS_LINKEDSTACK_H
#define GTEST_LISTS_LINKEDSTACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int value;
    struct Node *prox;
};

struct LinkedStack{
    struct Node* head;
    int length;
};

struct LinkedStack* initLinkedStack(){
    struct LinkedStack* stack;
    stack = (struct LinkedStack*) malloc(sizeof(struct LinkedStack));
    stack->length = 0;
    stack->head = NULL;
    return stack;
}

struct Node* newNode(int value){
    struct Node* head;
    head = (struct Node*) malloc(sizeof(struct no));
    if(head == NULL){
        return NULL;
    }
    head->value = value;
    head->prox = NULL;
    return head;
}

//retornar true se a stack for nula ou vazia
bool vazia(struct LinkedStack* stack){
    if( stack == NULL || stack->length == 0){
        return true;
    }
    else{
        return false;
    }
}

//se a stack estiver nula, instancie a stack
//por causa da possibilidade de instanciacao usamos struct LinkedStack**
void stack(struct LinkedStack** stack, int value){
    if( vazia(*stack) ){
        *stack = initLinkedStack();
        (*stack)->head = newNode(value);
    }
    else {
        struct Node *aux = (struct Node*)malloc(sizeof(struct no));
        aux = newNode(value);
        aux->prox = (*stack)->head;
        (*stack)->head = aux;
    }
    (*stack)->length++;
}

//decrementar length se a stack não estiver nula ou vazia
void un_stack(struct LinkedStack* stack) {
    if ( stack == NULL || stack->length == 0 ){
        stack = initLinkedStack();
    }
    else{
        struct Node* aux = (struct Node*) malloc(sizeof(struct no));
        aux = NULL;
        if (stack->length != 1 ) {
            aux = stack->head->prox;
            stack->head = aux;
            stack->length--;
        } else{
            stack->length--;
            stack->head = aux;
        }
    }
}

//retorne a constante INT_MIN se a stack for nula ou vazia
int head(struct LinkedStack* stack){
    if( stack == NULL || stack->length == 0){
        return INT_MIN;
    }
    else{
        return stack->head->value;
    }

}

//retorne a constante INT_MIN se a stack for nula ou vazia
int un_stackRetornando(struct LinkedStack* stack) {
    if( stack == NULL || stack->length == 0){
        return INT_MIN;
    }
    else{
        int tmp = head(stack);
        un_stack(stack);
        return  tmp;
    }
}

void print_stack(struct LinkedStack* stack) {
    //usamos o aux para percorrer a lista
    if (!vazia(stack)) {
        struct Node* aux = stack->head;
        //navega partindo do head até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->value);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A stack está vazia!");
    }
}
#endif //GTEST_LISTS_LINKEDSTACK_H