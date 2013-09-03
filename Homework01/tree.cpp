#include "tree.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>

// Ok, so in the .cpp file, we implement only the methods, and we use the format:
//
// return_type class_name::method_name( parameters ){...}


void tree::add(int i){
    nodeAdd(i, &root)
}


// NOTE:

// While I am trying to be as original as possible about his entire assignment,
// I used this web-page for reference: http://www.thegeekstuff.com/2013/02/c
// -binary-tree/ I feel like my code ended up looking a lot like the code on
// that page, but I don't really know what I could have done to prevent that
// (given it's simplicity), so I've tried to make sure I understand and
// subsequently can explain what's going on.
void tree::nodeAdd(int leefVal, treeNode** node){

    // Here we set up a superpointer so that we can actually point it at more pointers.
    
    treeNode *holderNode = NULL; // Will be used for the insertion

    // If there's not a node where there needs to be, then allocate the memory,
    // and assign our data appropriately to a temporary node, then swap it in.
    if ( *node == NULL ){
        
        holderNode = (treeNode*)malloc(sizeof(treeNode));
        holderNode->leftChild  = NULL;
        holderNode->rightChild = NULL;
        holderNode->value      = leefVal;

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
          //
          //   root   placeholder                 
          //   / \   /                  
          //  /   \ /                   
          // y     z                    
                                      
        holderNode->value = leefVal;


        (*node)->rightChild = holderNode; // Here, we implicitly sever the connection between the original two nodes, and connect our placeholder node as the man in the middle.
    }
}

void tree::print(){
    recursePrint(root)
}

void tree::recursePrint(treeNode* node){
    if (node->leftChild){
        recursePrint(node->leftChild);
    }
    cout << node->value << endl;// Awwwww yeah, cout.
    if (node->rightChild){
        recursePrint(node->rightChild);
    }
}

void tree::depthFistSearch(){
    return;
}

void tree::breadthFirstSearch(){
    return;
}