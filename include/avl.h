#ifndef AVL_H
#define AVL_H


struct AvlNode {
    int value;
    int height;
    struct AvlNode* left;
    struct AvlNode* right;
    struct AvlNode* parent; 
};

struct AvlTree {
    struct BstNode *root;
    int amount;
};

struct AvlNode* new_avl_node(int value);
struct AvlNode* avl_search(struct AvlTree avl, int value);

#endif