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
#include "../avl_tree_t.h"
#include "../readFileLines.cpp"
#include "../names_c.h"

void rotateLeft(){
    tree_t<name_c*> myAVL;
    std::cout << "Rotate Left Test" << std::endl;
    
    name_c* word0 = new name_c();
    name_c* word1 = new name_c();
    name_c* word2 = new name_c();
    name_c* word3 = new name_c();

    // std::cout << "Got to here." << std::endl;
    
    word0->setName(std::string("0"));
    word1->setName(std::string("1"));
    word2->setName(std::string("2"));
    word3->setName(std::string("3"));
     
    // std::cout << "inserting words." << std::endl;
    myAVL.add(word0);
    myAVL.add(word1);
    myAVL.add(word2);
    myAVL.add(word3);

// std::cout << "Printing breadth first" << std::endl;
    myAVL.bfp();

}


void rotateRight(){
    tree_t<name_c*> myAVL;
    std::cout << "Rotate Right Test" << std::endl;


    name_c* word0 = new name_c();
    name_c* word1 = new name_c();
    name_c* word2 = new name_c();

    
    word0->setName(std::string("0"));
    word1->setName(std::string("1"));
    word2->setName(std::string("2"));
     
    std::cout << "inserting words." << std::endl;
    myAVL.add(word2);
    myAVL.add(word1);
    myAVL.add(word0);

    myAVL.bfp();
}

void rotateRightLeft(){
    tree_t<name_c*> myAVL;

    std::cout << "Rotate Right-Left Test" << std::endl;
    
    name_c* word0 = new name_c();
    name_c* word1 = new name_c();
    name_c* word2 = new name_c();
    
    word0->setName(std::string("0"));
    word1->setName(std::string("1"));
    word2->setName(std::string("2"));
     
    std::cout << "inserting words." << std::endl;
    myAVL.add(word0);
    myAVL.add(word2);
    myAVL.add(word1);

    myAVL.bfp();

}

void rotateLeftRight(){
    tree_t<name_c*> myAVL;
    std::cout << "Rotate Left-Right Test" << std::endl;

    
    name_c* word0 = new name_c();
    name_c* word1 = new name_c();
    name_c* word2 = new name_c();
    
    word0->setName(std::string("0"));
    word1->setName(std::string("1"));
    word2->setName(std::string("2"));
     
    std::cout << "inserting words." << std::endl;
    myAVL.add(word2);
    myAVL.add(word0);
    myAVL.add(word1);

    myAVL.bfp();

}


int main(int argc, char const *argv[])
{
    rotateLeft();
    rotateRight();
    rotateRightLeft();
    rotateLeftRight();
    
    return 0;
}

