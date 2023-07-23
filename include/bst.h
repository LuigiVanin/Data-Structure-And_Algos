#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <stdbool.h>

struct BstNode
{
    int value;
    struct BstNode *left;
    struct BstNode *right;
};

struct Bst
{
    struct BstNode *head;
    int amount;
    int deepth;
};

struct Bst *init_bst()
{
    struct Bst *bst = (struct Bst *)malloc(sizeof(struct Bst));
    bst->amount = 0;
    bst->deepth = 0;
    bst->head = NULL;

    return bst;
}

struct BstNode *create_bst_node(int value)
{
    struct BstNode *node = (struct BstNode *)malloc(sizeof(struct BstNode));
    node->value = value;
    node->right = NULL;
    node->left = NULL;

    return node;
}

#endif
