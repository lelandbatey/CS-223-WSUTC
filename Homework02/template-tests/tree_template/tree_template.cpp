#include <iostream>
#include <stdlib.h>
#include "node_template.cpp"
#include "tree_template.h"

using namespace std;

template <class T>
void tree_template<T>::add(T inVal){
    addNode(inVal, root);
}

template <class T>
void tree_template<T>::addNode(T inVal, node_template<T>* node){

    node_template<T>* holderNode = NULL; // Create new empty node.

    // If this node's null, then create a new one, set the value and append it to the tree.
    if (*node == NULL){
        holderNode = new node_template<T>();
        holderNode->setVal(inVal);

        node = holderNode;
    }

    if (inVal > (*node).getVal()){
        addNode(inVal, *node.getRight());

    } else if ( inVal > *node->getVal()){
        addNode(inVal, *node.getLeft());

    } else if ( inVal == *node->getVal()){
        addNode(inVal, *node.getRight());
    }

    return;
}


