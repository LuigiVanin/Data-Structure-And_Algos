#include "../include/bst.h"
#include <stdio.h>

struct Bst init_bst()
{
    struct Bst bst;
    bst.amount = 0;
    bst.deepth = 0;
    bst.root = NULL;

    return bst;
}

struct BstNode *create_bst_node(int value)
{
    struct BstNode *node = (struct BstNode *)malloc(sizeof(struct BstNode));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    return node;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void insert_bst(struct Bst *bst, int value)
{

    if (bst->root == NULL)
    {
        bst->root = create_bst_node(value);
        bst->amount++;
        bst->deepth = 0;
        return;
    }

    struct BstNode *current = bst->root;
    struct BstNode *new_node = create_bst_node(value);
    int deepth = 0;

    while (true)
    {

        deepth++;
        if (current->value < new_node->value)
        {
            if (current->right == NULL)
            {
                new_node->parent = current;
                current->right = new_node;
                bst->amount++;
                bst->deepth = max(bst->deepth, deepth);
                break;
            }
            current = current->right;
        }
        else
        {
            if (current->left == NULL)
            {
                new_node->parent = current;
                current->left = new_node;
                bst->amount++;
                break;
            }
            current = current->left;
        }
    }
}

int bst_has_value(struct Bst bst, int value)
{
    struct BstNode *current = bst.root;

    while (current != NULL)
    {
        if (current->value == value)
            return true;
        if (current->value < value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return false;
}

struct BstNode *bst_search(struct Bst bst, int value)
{
    struct BstNode *current = bst.root;

    while (current != NULL)
    {
        if (current->value == value)
            return current;
        if (current->value < value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return NULL;
}

// int main()
// {
//     struct Bst bst = init_bst();
//     insert_bst(&bst, 10);
//     insert_bst(&bst, 12);
//     insert_bst(&bst, 13);
//     insert_bst(&bst, 9);

//     printf("%d\n", bst.root->value);
//     printf("%d\n", bst.root->right->value);
//     printf("%d\n", bst.root->left->value);
//     printf("%d\n", bst.deepth);

//     bool res = bst_has_value(bst, 13);
//     printf("%d\n", res);

//     struct BstNode *node = bst_search(bst, 13);
//     if (node == NULL)
//     {
//         printf("Não foi encontrado!");
//     }
//     else
//     {
//         printf("Valor: %d\n", node->value);
//     }
// }
