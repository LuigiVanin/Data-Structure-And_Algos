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
    struct AvlNode* t2 = Y->left;

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
