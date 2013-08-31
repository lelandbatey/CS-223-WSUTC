#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
// Leland Batey
// Cpts 223
// Interview Questions


// Requirements:
//     Build a program that can create a binary search tree from an array of integers.
//     Then perform:
//         1. A depth first traversal
//         2. A breadth first traversal

//     Additionally, implement a stack, and implement a queue (for use with searches).



int recursePrint(treeNode *node){ // Prints out all the numbers in order.
    if (node->leftChild){
        recursePrint(node->leftChild);
    }
    printf("%d\n", node->value );
    if (node->rightChild){
        recursePrint(node->rightChild);
    }
    return 0;
}

int main()
{
    treeNode* root;
    int i;
    int x;

    for (i = 0; i <= 15; ++i)
    {
        for (x = 0; x <= 4; x++){ // This is just here to throw in some duplicate values to see how they're handled.
            nodeAdd(x, &root);
        }
        nodeAdd(i, &root);
    }
    recursePrint(root);
    return 0;
}