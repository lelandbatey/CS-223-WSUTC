#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 0
#endif

#include <iostream>
#include <string>
#include <vector>
#include "../lfbLib.h"
#include "alt_avl_tree.h"
#include "../readFileLines.cpp"


void rotWithRightChild(){
    tree_c myAVL;

    // myAVL.add(std::string("0"));
    myAVL.add(std::string("1"));
    myAVL.add(std::string("2"));
    myAVL.add(std::string("3"));

    std::cout << "==rotWithRightChild==" << std::endl;
    myAVL.bfp();
}

void rotWithLeftChild(){
    tree_c myAVL;

    myAVL.add(std::string("3"));
    myAVL.add(std::string("2"));
    myAVL.add(std::string("1"));
    std::cout << "--rotWithLeftChild--" << std::endl;
    myAVL.bfp();
}

void doubleWithRightChild(){
    tree_c myAVL;

    myAVL.add(std::string("2"));
    myAVL.add(std::string("3"));
    myAVL.add(std::string("1"));
    std::cout << "--doubleWithRightChild--" << std::endl;
    myAVL.bfp();
}

void doubleWithLeftChild(){
    tree_c myAVL;

    myAVL.add(std::string("3"));
    myAVL.add(std::string("1"));
    myAVL.add(std::string("2"));
    std::cout << "--doubleWithLeftChild--" << std::endl;
    myAVL.bfp();
}



int main(int argc, char const *argv[]) {

    rotWithRightChild();
    rotWithLeftChild();
    doubleWithRightChild();
    doubleWithRightChild();

    return 0;
}