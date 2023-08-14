#include "../include/bst.h"

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

void insert_bst(struct Bst *bst, int value)
{
    if (bst == NULL)
    {
        printf("BST is NULL\n");
        bst = init_bst();
    }

    if (bst->head == NULL)
    {
        bst->head = create_bst_node(value);
        bst->amount++;
        return;
    }

    struct BstNode *current = bst->head;
    struct BstNode *new_node = create_bst_node(value);

    // while(true) {

    // }
}
