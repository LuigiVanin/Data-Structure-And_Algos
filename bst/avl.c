#include "../include/avl.h"
#include <stdio.h>


struct AvlNode* new_avl_node(int value) {
    struct AvlNode* node = (struct AvlNode*)malloc(sizeof(struct AvlNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;
    return node;
}

struct AvlNode* avl_search(struct AvlTree avl, int value) {
    struct AvlNode* current = avl.root;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        if (current->value < value) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return NULL;
}

 left_balance(struct AvlNode* node) {
    struct AvlNode* y = node->right;
    struct AvlNode* t2 = y->left;

    y->left= node;
    node->right = t2;

    node->height = max_number(node->left->height, node->right->height) + 1;
    y->height = max_number(y->left->height, y->right->height) + 1;
    
    return t2;
}

void right_balance(struct AvlNode* node) {
    struct AvlNode* y = node->left;
    struct AvlNode* t3 = y->right;

    y->right = node;
    node->left = t3;

    node->height = max_number(node->left->height, node->right->height) + 1;
    y->height = max_number(y->left->height, y->right->height) + 1;

    return t3;
}

void get_balance(struct AvlNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->left->height - node->right->height;
}

struct AvlNode* insert(struct AvlNode* node, int value) 
{ 
    if (node == NULL) 
        return(newNode(value)); 
  
    if (value < node->value) 
        node->left  = insert(node->left, value); 
    else if (value > node->value) 
        node->right = insert(node->right, value); 
    else 
        return node; 
  
    node->height = 1 + max(height(node->left), height(node->right)); 
  
    int balance = getBalance(node); 
  
    if (balance > 1 && value < node->left->value) 
        return rightRotate(node); 
  
    if (balance < -1 && value > node->right->value) 
        return leftRotate(node); 
  
    if (balance > 1 && value > node->left->value) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    if (balance < -1 && value < node->right->value) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
} 
