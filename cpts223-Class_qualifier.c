#include <stdio.h>
#include <stdlib.h>
// Leland Batey
// Cpts 223
// Interview Questions


// Requirements:
//     Build a program that can create a binary search tree from an array of integers.
//     Then perform:
//         1. A depth first traversal
//         2. A breadth first traversal

//     Additionally, implement a stack, and implement a queue.

typedef struct node{
    int value;
    struct node *leftChild;
    struct node *rightChild;
    // node *parent;// I'm going to implement these things with a parent, we'll see how this goes :/
} treeNode;

// Adds a value to the tree, creating a root node if necessary
void nodeAdd(int leefVal, treeNode **node){
    // Here we set up a superpointer so that we can actually point it at a bunch of stuff.
    
    treeNode *holderNode = NULL; // Will be used for the insertion

    if ( *node == NULL ){
        
        holderNode = (treeNode*)malloc(sizeof(treeNode));
        holderNode->leftChild  = NULL;
        holderNode->rightChild = NULL;
        holderNode->value = leefVal;

        *node = holderNode;
        return;
    } 

    if ( leefVal > (*node)->value ){ // If it's bigger than our node, check out what's happening on the right node
        nodeAdd(leefVal, &(*node)->rightChild);
    }

    if (leefVal < (*node)->value){
        nodeAdd(leefVal, &(*node)->leftChild);
    }
}

void printout(treeNode *node) {
   if(node->leftChild) printout(node->leftChild);
   printf("%d\n",node->value);
   if(node->rightChild) printout(node->rightChild);
}

int main()
{
    treeNode *root;
    int i;

    for (i = 0; i <= 15; ++i)
    {
        nodeAdd(i, &root);
    }
    printout(root);
    return 0;
}