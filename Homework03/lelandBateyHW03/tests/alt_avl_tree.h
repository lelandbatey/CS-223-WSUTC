#include "../avl_node_t.h"
#include <iostream>
#include <queue>

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 0
#endif

#ifndef _RIGHT_
#define _RIGHT_ 0
#endif

#ifndef _LEFT_
#define _LEFT_ 1
#endif

class tree_c
{
    private:
        node_t<std::string>* root;

    void addNode(node_t<std::string>*& node, std::string inStr ){
        // std::cout << inStr << std::endl;
        // std::cout << node << std::endl;
        // prntNodeInfo(node, true);
        if(node == NULL) {  // (1) If we are at the end of the tree place the value
            node = new node_t<std::string>;
            node->setVal(inStr);
             
        } else if(inStr < node->getVal()){  //(2) otherwise go left if smaller
            addNode(node->getLeft(), inStr);    
            if(height(node->getLeft()) - height(node->getRight()) == 2){
        
                if(inStr < node->getLeft()->getVal())
                    // rotateLeftOnce(node);
                    rotateWithLeftChild(node);
                else
                    // rotateLeftTwice(node);
                    doubleWithLeftChild(node);
            }
         } else if(inStr > node->getVal()){ // (3) otherwise go right if bigger
            addNode(node->getRight(), inStr);
            if(height(node->getRight()) - height(node->getLeft()) == 2){
                if(inStr > node->getRight()->getVal())
                    // rotateRightOnce(node);
                    rotateWithRightChild(node);
                else
                    // rotateRightTwice(node);
                    rotateWithLeftChild(node);
            }
        }
        // return node;

    }

    // Largely taken from here:
    // http://stackoverflow.com/a/4219934
    int height(node_t<std::string>*& node){
        int left, right;

        if(node==NULL)
            return 0;
        left = height(node->getLeft());
        right = height(node->getRight());
        
        if(left > right)
            return left+1;
        else
            return right+1;
    }

    // void rotateLeftOnce(node_t<std::string>*& node){
    //      node_t<std::string> *otherNode;

    //      otherNode = node->getLeft();
    //      node->setLeft(otherNode->getRight());
    //      otherNode->setRight(node);
    //      node = otherNode;
    // }


    // void rotateLeftTwice(node_t<std::string>*& node){
    //      rotateRightOnce(node->getLeft());
    //      rotateLeftOnce(node);
    // }


    // void rotateRightOnce(node_t<std::string>*& node){
    //      node_t<std::string> *otherNode;

    //      otherNode = node->getRight();
    //      node->setRight(otherNode->getLeft());
    //      otherNode->setLeft(node);
    //      node = otherNode;
    // }


    // void rotateRightTwice(node_t<std::string>*& node){
    //      rotateLeftOnce(node->getRight());
    //      rotateRightOnce(node);
    // }


    void rotateWithLeftChild( node_t<std::string>*& node){
        node_t<std::string>* k2 = node->getLeft();

        k2->setLeft(node->getRight());
        node->setRight(k2);
        node = k2;
    }

    void rotateWithRightChild( node_t<std::string>*& node){
        node_t<std::string>* k2 = node->getRight();

        node->setRight(k2->getLeft());
        k2->setLeft(node);
        node = k2;
    }

    void doubleWithRightChild( node_t<std::string>*& node){
        rotateWithRightChild(node->getRight());
        rotateWithLeftChild(node);
    }

    void doubleWithLeftChild(node_t<std::string>*& node){
        rotateWithRightChild(node->getLeft());
        rotateWithLeftChild(node);
    }

    int getBalance(node_t<std::string>* node){
        return ( height(node->getRight()) - height(node->getLeft()) );
    }

    void prntNodeInfo(node_t<std::string>*& node, bool override){
        // Print info about this node

        if (LIGHT_DEBUG || override) {
            std::cout << "\t-- Printing Node Information : --"   << std::endl;
            std::cout << "\t A : " << node              << std::endl;
            std::cout << "\t V : " << node->getVal()    << std::endl;
            std::cout << "\t L : " << node->getLeft()   << std::endl;
            std::cout << "\t R : " << node->getRight()  << std::endl;
        }
    }

public:

    tree_c() {
        root = NULL;
    }

    void add(std::string inStr ){
        addNode(root, inStr);
    }

    void bfp(){

        std::queue<node_t<std::string>*> Q;

        node_t<std::string>* node;
        node_t<std::string>* markNode;
        markNode = root->getLeft();

        int i = 0;
        bool search = false;

        // std::cout << "Root info: " << std::endl;
        // prntNodeInfo(root);
        Q.push(root);

        while (!Q.empty()){
            node = Q.front();
            Q.pop();


            if ( node == markNode || search == true) {
                
                if (node==markNode && search == false) {
                    i++;                    
                }

                search = true;
                if (node->getLeft()) {
                    markNode = node->getLeft();
                    // i++;
                    search = false;
                } else if (node->getRight()){
                    markNode = node->getRight();
                    // i++;
                    search = false;
                } else {
                    // if (Q.front()) {
                    //     i++;
                    //     markNode = Q.front();
                    // } else {
                    //     // i++;
                    // }
                }
            }
            std::cout << "  Level: " << i << std::endl;
            std::cout << "  " << node->getVal();
            std::cout << "," << getBalance(node) << std::endl;
            // prntNodeInfo(node, true);
            // prntNodeInfo(markNode);

            if (node->getLeft()) {
                Q.push(node->getLeft());
            }
            if (node->getRight()) {
                Q.push(node->getRight());
            }
        } 
    }

};