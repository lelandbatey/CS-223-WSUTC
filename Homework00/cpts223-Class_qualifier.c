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

//     Additionally, implement a stack, and implement a queue (for use with searches).

typedef struct node{
    int value;
    struct node *leftChild;
    struct node *rightChild;
    // node *parent;// I'm going to implement these things with a parent, we'll see how this goes :/
} treeNode;

// typedef struct treeQNode{
//     struct node *node;
// }

// A type defined as a structure which contains a pointer to the next item in
// the queue and a pointer to it's corresponding node in the binary search tree.
typedef struct qNode_s {
    struct qNode_s *next_p;
    treeNode *bstNode;
} qNode;


// void push(int value){
//     qNode *tempQNode;

//     tempQNode = (qNode*)malloc(sizeof(treeNode));

// }


// NOTE:

// While I am trying to be as original as possible about his entire assignment,
// I used this web-page for reference: http://www.thegeekstuff.com/2013/02/c
// -binary-tree/ I feel like my code ended up looking a lot like the code on
// that page, but I don't really know what I could have done to prevent that
// (given it's simplicity), so I've tried to make sure I understand and
// subsequently can explain what's going on.

// Adds a value to the tree, creating a root node if necessary
void nodeAdd(int leefVal, treeNode **node){
    // Here we set up a superpointer so that we can actually point it at more pointers.
    
    treeNode *holderNode = NULL; // Will be used for the insertion

    // If there's not a node where there needs to be, then allocate the memory,
    // and assign our data appropriately to a temporary node, then swap it in.
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

    if (leefVal < (*node)->value){ // Otherwise, check out the left node
        nodeAdd(leefVal, &(*node)->leftChild);
    }

    if (leefVal == (*node)->value){ // Oh noes, it's equal :( Now we gotta do some black magic...
        // So we allocate the appropriate placeholder node
        holderNode = (treeNode*)malloc(sizeof(treeNode));
        holderNode->leftChild  = NULL;
        holderNode->rightChild = (*node)->rightChild; // Here we set the it so that the right-side child of the temporary node points to the same node that is currently being pointed to by the main tree node. It might look like this:
          //   root   placeholder                 
          //   / \   /                  
          //  /   \ /                   
          // y     z                    
                                      
        holderNode->value = leefVal;


        (*node)->rightChild = holderNode; // Here, we implicitly sever the connection between the original two nodes, and connect our placeholder node as the man in the middle.
    }
}


int recursePrint(treeNode *node){
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
    treeNode *root;
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