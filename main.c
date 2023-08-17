#include <stdio.h>
#include <stdlib.h>
#include "include/arrayList.h"
// #include "include/linkedList.h"
// #include "include/doublyLinkedList.h"
// #include "include/arrayQueue.h"
// #include "include/linkedQueue.h"
// #include "include/bogo_search.h"
// #include "include/binary_search.h"
// #include "include/graph_adj.h"
// #include "include/graph_matrix.h"
// #include "include/dfs.h"
// #include "include/bfs.h"
// #include "include/insertionSort.h"
// #include "include/bogo_sort.h"
// #include <time.h>
// #include "include/bubbleSort.h"
// #include "include/quicksort.h"
// #include "include/dijkstra.h"
#include "include/bst.h"

const int SIZE = 4;

int main()
{
    struct Bst bst = init_bst();
    insert_bst(&bst, 10);
    insert_bst(&bst, 12);
    insert_bst(&bst, 13);
    insert_bst(&bst, 9);

    printf("%d\n", bst.root->value);
    printf("%d\n", bst.root->right->value);
    printf("%d\n", bst.root->left->value);
    printf("%d\n", bst.deepth);

    bool res = bst_has_value(bst, 13);
    printf("%d\n", res);

    struct BstNode *node = bst_search(bst, 13);
    if (node == NULL)
    {
        printf("Não foi encontrado!");
    }
    else
    {
        printf("Valor: %d\n", node->value);
    }
}
