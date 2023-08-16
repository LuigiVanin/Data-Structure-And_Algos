#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <stdbool.h>

struct BstNode
{
    int value;
    struct BstNode *left;
    struct BstNode *right;
    struct BstNode *parent;
};

struct Bst
{
    struct BstNode *root;
    int amount;
    int deepth;
};

struct Bst init_bst();

struct BstNode *create_bst_node(int value);

void insert_bst(struct Bst *bst, int value);

#endif
