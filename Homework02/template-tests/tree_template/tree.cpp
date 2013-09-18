#include "tree.h"


void lbtree::addNode(int inVal, node_template<int>* node){
    node_template<int>* holderNode = NULL; // Create new empty node.

    // If this node's null, then create a new one, set the value and append it to the tree.
    if (node == NULL){
        holderNode = new node_template<int>();
        holderNode->setVal(inVal);

        node = holderNode;
    }

    if (inVal > (*node).getVal()){
        addNode(inVal, *node->getRight());

    } else if ( inVal > *node->getVal()){
        addNode(inVal, *node->getLeft());

    } else if ( inVal == *node->getVal()){
        addNode(inVal, *node->getRight());
    }

    return;
}

void lbtree::add(int inVal){
    addNode(inVal, &root);
}
