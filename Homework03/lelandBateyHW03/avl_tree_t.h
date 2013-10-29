#include "avl_node_t.h"
#include <iostream>

#ifndef _RIGHT_
#define _RIGHT_ 0
#endif

#ifndef _LEFT_
#define _LEFT_ 1
#endif

template <class T>
class tree_t
{

private:
    node_t<T>* root;

    // Amalgamation of my previous code, but with some solid conventions taken from the awesome tree example by Steven Hickson

    // The new parentNode is there to allow us to set the parent (makes life easier for AVL trees)
    void addNode(T &inVal, node_t<T>*& inNode, node_t<T>*& parentNode) {

        if (DEBUG) {
            std::cout << "\t-- Printing addNode Info: --" << std::endl;
            std::cout << "\tInput Value : " << inVal->getVal() << std::endl;
            std::cout << "\tinNode      : " << inNode << std::endl;
            if (inNode && inNode->getVal()) {            
                std::cout << "\tinNode Value: " << inNode->getVal()->getVal() << std::endl;
            }
            std::cout << "\tParent Node : " << parentNode << std::endl;
        }

        if ( inNode == NULL ){
            inNode = new node_t<T>();
            inNode->setVal(inVal);
            inNode->setParent(parentNode);
            // inNode->getVal()->print(); // Here we print the value of the node
        } else if (*(inNode->getVal()) > *(inVal)) {

            if (DEBUG) {
                std::cout << "\t Insert-value is smaller than current node. ";
                std::cout << inNode->getVal()->getVal() << " > " << inVal->getVal() << std::endl;
                std::cout << "\t Going to the left." << std::endl;
            }

            addNode(inVal, inNode->getLeft(), inNode);

            nodeBalance(inVal,inNode, _LEFT_);

            // if (inNode) {
            //     // BALANCING TREE
            //     // If the heights are imbalanced


            //     if (abs( height(inNode->getRight()) - height(inNode->getLeft()))==2) {
            //         std::cout << "\t Balance is: " << getHeight(inNode) << std::endl;
            //         prntNodeInfo(inNode);
            //         // If the right hand side is imbalanced
            //         if ( inNode->getRight()) {
            //             if (inVal > inNode->getRight()->getVal()){
            //                 // Single rotation right
            //                 rotateRight(inNode);
            //             } else {
            //                 // Else, double rotation Left-Right
            //                 rotateLR(inNode);
            //             }
            //         } else {
            //             // On the off chance there *is* no right node :)
            //             rotateLR(inNode);
            //         }
            //     }
            // }

        } else if (  *(inNode->getVal()) < *(inVal) ) {

            if (DEBUG) {
                std::cout << "\t Insert-value is larger than current node. ";
                std::cout << inNode->getVal()->getVal() << " < " << inVal->getVal() << std::endl;
                std::cout << "\t Going to the right" << std::endl;
            }


            addNode(inVal, inNode->getRight(), inNode);

            nodeBalance(inVal,inNode,_RIGHT_);

            

        } else if ( *(inNode->getVal()) == *(inVal) ){
            
            if (eqFunc){

                std::cout << "DANGER WILL ROBINSON THESE ARE EQUAL!!" << std::endl;
                eqFunc( inNode->getVal(), inVal ); // The variables that's needed 
                addNode(inVal, inNode, parentNode);
            }
        } else {
            // Only happens if all the other conditions (smaller than, larger
            // than, equal to) all fail. This is only really likely to happen
            // when the tree is trying to be used to store data structures
            // without properly implemented comparison overloading.
            if (DEBUG) {
                std::cout << "well, it seems the value that's trying to be added is neither smaller, nor larger, nor equal to the value in the node. Tis a shame..." << std::endl;

            }
        }
    }

    void nodeBalance(T& inVal, node_t<T>*& inNode, int direction){

        // GIGANTIC FUNCTION for balancing a node/subtree

        // BALANCING TREE
        // If the heights are imbalanced
        // if (inNode) {
        if (abs( height(inNode->getLeft()) - height(inNode->getRight()))==2) {
            // std::cout << "\t Balance is: " << getHeight(inNode) << std::endl;
            // prntNodeInfo(inNode);

            if (direction == _LEFT_) {
                if (inNode->getLeft()) {
                    if (inVal > inNode->getLeft()->getVal()){
                        // Single rotation left
                        rotateLeft(inNode);
                    } else {
                        // Else, double rotate Right-Left
                        rotateRL(inNode);
                    }
                } else {
                    rotateRL(inNode);
                }
            } else if ( direction == _RIGHT_) {
                if ( inNode->getRight()) {
                    if (inVal > inNode->getRight()->getVal()){
                        // Single rotation right
                        rotateRight(inNode);
                    } else {
                        // Else, double rotation Left-Right
                        rotateLR(inNode);
                    }
                } else {
                    // On the off chance there *is* no right node :)
                    rotateLR(inNode);
                }
            }
        }

    }


    void prntNodeInfo(node_t<T>*& node){

        // Print info about this node
        // 

        if (DEBUG) {
            std::cout << "\t-- Printing Node Information : --"   << std::endl;
            std::cout << "\tAddress     : " << node              << std::endl;
            std::cout << "\tValue       : " << node->getVal()->getVal()    << std::endl;
            std::cout << "\tLeft Child  : " << node->getLeft()   << std::endl;
            std::cout << "\tRight Child : " << node->getRight()  << std::endl;
            std::cout << "\tParent Node : " << node->getParent() << std::endl;
        }

        if (LIGHT_DEBUG) {
            std::cout << "\t-- Printing Node Information : --"   << std::endl;
            std::cout << "\t A : " << node              << std::endl;
            std::cout << "\t V : " << node->getVal()->getVal()    << std::endl;
            std::cout << "\t L : " << node->getLeft()   << std::endl;
            std::cout << "\t R : " << node->getRight()  << std::endl;
            // std::cout << "\tParent Node : " << node->getParent() << std::endl;
        }


    }


    void recursePrint(node_t<T>*& node) {
        
        if (DEBUG){
            // std::cout << node->getLeft() << std::endl;
            // std::cout << node->getRight() << std::endl;
            std::cout << "Attempting to recurse to the left." << std::endl;
        }

        if (node->getLeft()){
            recursePrint(node->getLeft());
        } else {
            if (DEBUG) {
                std::cout << "This node had no LEFT child." << std::endl;
            }
        }
        // node->getVal()->print();
        // std::cout << node->getVal()->getVal() << std::endl;
        prntNodeInfo(node);

        if (node->getRight()) {
            recursePrint(node->getRight());
        } else {
            if (DEBUG) {
                std::cout << "This node has no RIGHT child" << std::endl;
            }
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


    // This is largely adapted from here:
    // http://stackoverflow.com/a/4219934
    void rotateRight(node_t<T>*& node){
        node_t<T>* tempNode;

        if (DEBUG) {
            recursePrint(root);
        }

        tempNode = node->getRight();
        node->setRight(tempNode->getLeft());
        tempNode->setLeft(node);
        node = tempNode;
    }

    void rotateLeft(node_t<T>*& node){
        node_t<T>* tempNode;

        if (DEBUG) {
            recursePrint(root);
        }

        tempNode = node->getLeft();
        node->setLeft(tempNode->getRight());
        tempNode->setRight(node);
        node = tempNode;
    }

    void rotateLR(node_t<T>*& node){
        rotateLeft(node->getRight());
        rotateRight(node);
    }

    void rotateRL(node_t<T>*& node){
        rotateRight(node->getLeft());
        rotateLeft(node);
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
        if (DEBUG) {
            std::cout << "Adding a node" << std::endl;
        }
        node_t<T>* tmp = NULL;
        addNode( inVal, root, tmp );
    }



    void print() {
        if (DEBUG){
            std::cout << " ## Printing the tree! ##" << std::endl;
        }
        recursePrint(root);
    }


    // Basis for this height method from here:
    // http://stackoverflow.com/a/4219934
    int height(node_t<T>* node){
        int r,l;

        if (node == NULL){
            return 0;
        }
        l = height(node->getLeft());
        r = height(node->getRight());

        if (l>r) {
            return l+1;
        } else {
            return r+1;
        }
    }

    int getHeight(node_t<T>* node){
        return ( height(node->getRight()) - height(node->getLeft()) );
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