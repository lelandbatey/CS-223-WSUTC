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


int main(int argc, char const *argv[])
{
    tree_t<name_c*> myAVL;
    name_c* tempName;
    std::vector<std::string> nameList = getNames(std::string(argv[1]));

    for (unsigned int i = 0; i < nameList.size(); ++i) {
        if (strToBool(nameList[i])) {
           
            tempName = new name_c();
            tempName->setName( strFlog(nameList[i])); // Uppercases before making an object out of it.
            
            myAVL.add(tempName);
        }
    }

    myAVL.bfp();

    return 0;
}

