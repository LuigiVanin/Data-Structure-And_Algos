#ifndef GTEST_LISTS_ARRAYSTACK_H
#define GTEST_LISTS_ARRAYSTACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct ArrayStack {
    int* array;
    int length;    //tam do array
    int max;     //max de array no array
};

struct ArrayStack* initArrayStack(int tamArray){
    struct ArrayStack* stack = (struct ArrayStack*) malloc(sizeof(struct ArrayStack));
    if (tamArray < 0)
        return NULL;
    stack->max = 0;
    stack->length = tamArray;
    stack->array = (int*)calloc(tamArray, sizeof(int));
    return stack;
}

void double_stack(struct ArrayStack* stack){
    stack->length = 2*(stack->length);
    stack->array = (int*) realloc(stack->array, stack->length * sizeof(int));
}

void emstackr(struct ArrayStack** stack, int value){
    if(*stack == NULL){
        *stack = initArrayStack(10);
    }
    else if((*stack)->max == (*stack)->length){
        double_stack(*stack);
    }
    (*stack)->array[(*stack)->max] = value;
    ((*stack)->max)++;
}

bool is_empty(struct ArrayStack* stack) {
    if(stack == NULL || stack->max == 0){
        return true;
    }
    else{
        return false;
    }
}

int top(struct ArrayStack* stack){
    if( stack == NULL || stack->max == 0 ){
        return INT_MIN;
    }
    else{
        return stack->array[stack->max - 1];
    }
}

void un_stack(struct ArrayStack* stack){
    if(stack->max > 0){
        (stack->max)--;
    }
}

int un_stack_with_return(struct ArrayStack* stack){
    if( stack == NULL || stack->max == 0 ){
        return INT_MIN;
    }
    int tmp = stack->array[stack->max - 1];;
    (stack->max)--;
    return tmp;
}

void print_stack(struct ArrayStack* stack){
    printf("_\n");
    for(int i = stack->max - 1; i >= 0; i--){
        printf("%d\n",stack->array[i]);
    }
    printf("_\n\n");
}
#endif //GTEST_LISTS_ARRAYSTACK_H