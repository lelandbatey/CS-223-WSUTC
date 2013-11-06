#ifndef DEBUG
#define DEBUG 1
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
// #include "../names_c.h"


int main(int argc, char const *argv[])
{
    tree_c myAVL;
    // name_c* tempName;
    std::vector<std::string> nameList = getNames(std::string(argv[1]));

    for (unsigned int i = 0; i < nameList.size(); ++i) {
        if (strToBool(nameList[i])) {
            std::cout << i << std::endl;
            // tempName = new name_c();
            // tempName->setName( strFlog(nameList[i])); // Uppercases before making an object out of it.
            // std::cout << strFlog(nameList[i]) << std::endl;
            myAVL.add(strFlog(nameList[i]));
        }
    }

    myAVL.bfp();


    return 0;
}

