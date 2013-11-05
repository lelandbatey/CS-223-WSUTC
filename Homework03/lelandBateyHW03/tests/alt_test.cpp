#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 1
#endif

#include <iostream>
#include <string>
#include <vector>
#include "../lfbLib.h"
#include "alt_avl_tree.h"
#include "../readFileLines.cpp"


void rotWithRightChild(){
    tree_c myAVL;

    // // myAVL.add(std::string("0"));
    // myAVL.add(std::string("1"));
    // myAVL.add(std::string("2"));
    // myAVL.add(std::string("0"));

    // std::cout << "==rotWithRightChild==" << std::endl;
    // myAVL.bfp();
    // std::cout << "finish" << std::endl;

    node_t* k1 = 0;
    node_t* k2 = 0;
    node_t* x  = 0;
    k1 = new node_t();
    k2 = new node_t();
    x = new node_t();

    k2->setVal(std::string("3"));
    k1->setVal(std::string("2"));
    x->setVal(std::string("1"));

    k2->setRight(k1);
    k1->setRight(x);

    // node_t* temp = &k2;
    // temp = k2;
    myAVL.prntNodeInfo(k2,true);
    myAVL.prntNodeInfo(k1,true);
    myAVL.prntNodeInfo(x,true);


    myAVL.rotateWithRightChild(k2);

    myAVL.prntNodeInfo(k2,true);
    myAVL.prntNodeInfo(k1,true);
    myAVL.prntNodeInfo(x,true);
}


void doubleWithRightChild(){

    tree_c myAVL;

    // myAVL.add(std::string("997"));
    // myAVL.add(std::string("999"));
    // myAVL.add(std::string("998"));
    // std::cout << "--rotWithLeftChild--" << std::endl;
    // myAVL.bfp();

    node_t* k1 = 0;
    node_t* k2 = 0;
    node_t* x  = 0;
    k1 = new node_t();
    k2 = new node_t();
    x = new node_t();

    k2->setVal(std::string("1"));
    k1->setVal(std::string("7"));
    x->setVal(std::string("2"));

    k2->setRight(k1);
    k1->setLeft(x);

    std::cout << "Printing doubleWithRightChild" << std::endl;
    myAVL.prntNodeInfo(k2,true);
    myAVL.prntNodeInfo(k1,true);
    myAVL.prntNodeInfo(x,true);
    std::cout << "Now rotating" << std::endl;

    myAVL.doubleWithRightChild(k2);
    std::cout << "Rotate done" << std::endl;
    myAVL.root = k2;
    myAVL.bfp();
    // myAVL.prntNodeInfo(k2,true);
    // myAVL.prntNodeInfo(k1,true);
    // myAVL.prntNodeInfo(x,true);


}
void rotWithLeftChild(){

    tree_c myAVL;

    myAVL.add(std::string("3"));
    myAVL.add(std::string("2"));
    myAVL.add(std::string("1"));
    // std::cout << "--doubleWithRightChild--" << std::endl;
    myAVL.bfp();
}

void doubleWithLeftChild(){
    tree_c myAVL;

    // myAVL.add(std::string("3"));
    // myAVL.add(std::string("1"));
    // myAVL.add(std::string("2"));
    // std::cout << "--doubleWithLeftChild--" << std::endl;
    // myAVL.bfp();

    node_t* k1 = 0;
    node_t* k2 = 0;
    node_t* x  = 0;
    k1 = new node_t();
    k2 = new node_t();
    x = new node_t();

    k2->setVal(std::string("10"));
    k1->setVal(std::string("5"));
    x->setVal(std::string("7"));

    k2->setLeft(k1);
    k1->setRight(x);

    std::cout << "Printing doubleWithLeftChild" << std::endl;
    myAVL.prntNodeInfo(k2,true);
    myAVL.prntNodeInfo(k1,true);
    myAVL.prntNodeInfo(x,true);
    std::cout << "Now rotating" << std::endl;

    myAVL.doubleWithLeftChild(k2);
    std::cout << "Rotate done" << std::endl;
    myAVL.root = k2;
    myAVL.bfp();
    // myAVL.prntNodeInfo(k2,true);
    // myAVL.prntNodeInfo(k1,true);
    // myAVL.prntNodeInfo(x,true);

}



int main(int argc, char const *argv[]) {

    rotWithRightChild();
    rotWithLeftChild();
    doubleWithRightChild();
    doubleWithLeftChild();

    return 0;
}