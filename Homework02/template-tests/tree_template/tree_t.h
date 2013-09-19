#include "node_t.h"
#include <iostream>

template <class T>
class tree_t
{

private:
    node_t<T>* root;

    // Amalgamation of my previous code, but with some solid conventions taken from the awesome tree example by Steven Hickson
    void addNode(T &inVal, node_t<T>*& inNode) {
        if ( inNode == NULL ){
            inNode = new node_t<T>();
            inNode->setVal(inVal);   
        } else if (inNode->getVal() > inVal) {
            addNode(inVal, inNode->getRight());
        } else if (inNode->getVal() < inVal) {
            addNode(inVal, inNode->getLeft());
        }
    }

    void recursePrint(node_t<T>*& node) {
        if (node->getLeft()){
            recursePrint(node->getLeft());
        }
        std::cout << node->getVal() << std::endl;

        if (node->getRight()) {
            recursePrint(node->getRight());
        }
    }

public:
    // tree_t(arguments);
    // ~tree_t();
    tree_t() {
        root = NULL;
    }

    void add(T &inVal) {
        addNode( inVal, root );
    }

    void print() {
        recursePrint(root);
    }

};