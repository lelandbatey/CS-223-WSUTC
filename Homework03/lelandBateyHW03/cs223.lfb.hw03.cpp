

#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 0
#endif

#include <iostream>
#include <string>
#include <vector>
#include "lfbLib.h"
// #include "avl_tree_t.h"
#include "alt_avl_tree.h"
#include "readFileLines.cpp"
#include "names_c.h"



int main(int argc, char const *argv[]) {

    if (argc < 2){
        std::cout << "Dude, input a file name. Seriously... :/" << std::endl;
        return 0;
    }

    // tree_t<name_c*> myAVL;
    tree_c myAVL;
    name_c* tempName;
    std::vector<std::string> nameList = getNames(std::string(argv[1]));

    // std::cout << sizeof(nameList) << std::endl;

    for (unsigned int i = 0; i < nameList.size(); ++i) {
        if (strToBool(nameList[i])) {
            
            if (DEBUG) {
                std::cout << i << ' ';
                std::cout << nameList[i] << std::endl;
            }

            // tempName = new name_c();
            // tempName->setName( strFlog(nameList[i])); // Uppercases before making an object out of it.
            
            if (DEBUG) {
                std::cout << "-- " << tempName->getVal() << std::endl;
                std::cout << "-- " << tempName->getNumName() << std::endl;
            }

            myAVL.add(strFlog(nameList[i]));
            // myAVL.bfp();

        }
    }

    // std::cout << " Get tree height: " << myAVL.getTreeHeight() << std::endl;
    // myAVL.print();

    // myAVL.setFindEqFunc(&compareStrToName);

    std::string input;
    std::string otherIn;
    bool doneFlag = false;
    // std::string thing;
    // std::cin >> thing;

    while (!doneFlag){
        input = "";
        
        std::getline(std::cin, input);
        otherIn = getAfter(input," ");
        input = getBefore(input, " ");

        input = strUpper(input);
        otherIn = strUpper(otherIn);

        if (input == "EXIT"){
            // Currently we actually don't know what we're supposed to do when we are asked to 
            return 0;
        } else if ( input == "FIND") {
            myAVL.find(otherIn);
        } else if ( input == "HEIGHT") {
            std::cout << myAVL.getTreeHeight() << std::endl;
        } else if (input == "PRINT") {
            myAVL.bfp();
        }
    }

    return 0;
}


