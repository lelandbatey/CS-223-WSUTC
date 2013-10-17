#include "node_t.h"
#include <iostream>

template <class T>
class tree_t
{

private:
    node_t<T>* root;

    // Amalgamation of my previous code, but with some solid conventions taken from the awesome tree example by Steven Hickson

    // So, something a bit different about this 
    void addNode(T &inVal, node_t<T>*& inNode) {
        if ( inNode == NULL ){
            inNode = new node_t<T>();
            inNode->setVal(inVal);
            // inNode->getVal()->print(); // Here we print the value of the node
        } else if (*(inNode->getVal()) > *(inVal)) {
            addNode(inVal, inNode->getRight());
        } else if (  *(inNode->getVal())   < *(inVal) ) {
            addNode(inVal, inNode->getLeft());
        } else if ( *(inNode->getVal()) == *(inVal) ){
            
            if (eqFunc){
                eqFunc( inNode->getVal(), inVal ); // The variables that's needed 
                addNode(inVal, inNode);
            }
        }
    }

    void recursePrint(node_t<T>*& node) {
        if (node->getLeft()){
            recursePrint(node->getLeft());
        }
        node->getVal()->print();
        // std::cout <<  << std::endl;

        if (node->getRight()) {
            recursePrint(node->getRight());
        }
    }

    void (*eqFunc)(T,T); 
    // Ok, this things pretty gnarly, I'll explain:
    //
    // Basically, when we are trying to insert a value that's equal to a value
    // that's already in the tree, by default we *ignore* that value and it is
    // just discarded.
    //
    // However, what if we don't want to just discard a value when we find
    // it's already in the tree? The point of the above is to be a pointer to
    // a function that will do some kind of mutation on the object that's
    // trying to be inserted, then re-try to insert it. It's recursive, so
    // even if stuff get's mutated reliably, it works 
    //
    // This function MUST be specified before anything starts to get inserted,
    // if you want it to mutate if it finds equality. However, if ommitted,
    // it'll default to ignoring equal values.

    int (*findEqFunc)(T,std::string);
    // Similar story with this.
    //
    // I will build a recursive function that will traverse the tree, trying
    // to "find" a value. However, the thing we're going to be trying to find
    // is a std::string, and we need to know how to find a compare a
    // std::string to some facet of our object. So, we must once again be
    // provided with a function that "knows" how to properly make that
    // comparison and returns an int telling us whether we've found our node
    // or not.
    //
    // Must return 1 if they ARE equal.

    int recursiveFind(std::string str, node_t<T>*& node){
        // std::cout << node->getVal()->getName() << std::endl;


        if (findEqFunc(node->getVal(), str)){
            // We're going to leave the printing to the find function.
            return 1;
        }
        if (node->getRight()){
            if (recursiveFind(str, node->getRight())){
                return 1;
            }
        }
        if (node->getLeft()){
            if (recursiveFind(str, node->getLeft())){
                return 1;
            }
        }
        // Else:
        // Nothing found, nothing found in either sub tree.
        return 0;

    }

public:
    // tree_t(arguments);
    // ~tree_t();
    tree_t() {
        root = NULL;
        eqFunc= NULL; 
        findEqFunc = NULL;
    }

    void add(T &inVal) {
        addNode( inVal, root );
    }

    void print() {
        if (DEBUG){
            std::cout << " ## Printing the tree! ##" << std::endl;
        }
        recursePrint(root);
    }

    void setEqFunc(void (*func)(T,T)){
        eqFunc = func;
    }

    void find(std::string str){
        if (recursiveFind(str,root)){
            return;
        } else {
            std::cout << "That animal does not exist in this zoo." << std::endl;
        }
    }

    void setFindEqFunc(int (*func)(T,std::string)){
        findEqFunc = func;
    }

};