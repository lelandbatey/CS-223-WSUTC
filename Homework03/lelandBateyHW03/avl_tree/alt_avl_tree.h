#include "alt_avl_node.h"
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


    void addNode(node_t*& node, std::string inStr ){
        // std::cout << inStr << std::endl;
        // std::cout << node << std::endl;
        // prntNodeInfo(node, true);
        if(node == NULL) {  // (1) If we are at the end of the tree place the value
            node = new node_t();
            node->setVal(inStr);
            // prntNodeInfo(node, true);
             
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
                    doubleWithRightChild(node); // RL insert, RL rotate
            }
        }
        // return node;

    }

    // Largely taken from here:
    // http://stackoverflow.com/a/4219934
    int height(node_t*& node){
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


    int recursiveFind(std::string str, node_t*& node){

        if (node->getVal() == str){ // If we FIND the node we're looking for

            std::cout << node->getVal();
            std::cout << "," << getBalance(node) << std::endl;
            
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

    int straightHeight(node_t* node){ 
        if (!node) {
            return 0;
        } else {
            return std::max(straightHeight( node->getRight() ), straightHeight( node->getLeft() ) )+1;
        }
    }

public:
    node_t* root;

    void rotateWithLeftChild( node_t*& k2){
        // std::cout << "Rote with LEFT child" << std::endl;
        node_t* k1 = k2->getLeft();
        k2->setLeft(k1->getRight());
        k1->setRight(k2);
        k2 = k1;
    }

    void rotateWithRightChild( node_t*& k2){
        node_t* k1 = k2->getRight();
        // k1->setRight(k2->getLeft());
        // k2->setRight(k1);
        k2->setRight(k1->getLeft());
        k1->setLeft(k2);
        k2 = k1;
    }

    void doubleWithRightChild( node_t*& k2){
        rotateWithLeftChild(k2->getRight());
        rotateWithRightChild(k2);
    }

    void doubleWithLeftChild(node_t*& k2){
        rotateWithRightChild(k2->getLeft());
        rotateWithLeftChild(k2);
    }

    int getBalance(node_t* node){
        return ( height(node->getRight()) - height(node->getLeft()) );
    }

    void prntNodeInfo(node_t*& node, bool override){
        // Print info about this node

        if (LIGHT_DEBUG || override) {
            std::cout << "\t-- Printing Node Information : --"   << std::endl;
            std::cout << "\t A : " << node              << std::endl;
            std::cout << "\t V : " << node->getVal()    << std::endl;
            std::cout << "\t L : " << node->getLeft()   << std::endl;
            std::cout << "\t R : " << node->getRight()  << std::endl;
        }
    }


    tree_c() {
        root = NULL;
    }

    void add(std::string inStr ){
        addNode(root, inStr);
    }

    void find(std::string str){
        if (recursiveFind(str,root)){
            return;
        } else {
            std::cout << "That item doesn't exist in this tree/db." << std::endl;
        }
    }

    int getTreeHeight(){
        return straightHeight(root);
    }

    void bfp(){

        std::queue<node_t*> Q;

        node_t* node;
        node_t* markNode;
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
                }
            }
            // std::cout << "  Level: " << i << std::endl;
            std::cout << node->getVal() << std::endl;
            // std::cout << "," << getBalance(node) << std::endl;
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