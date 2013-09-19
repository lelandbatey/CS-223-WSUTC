#include <iostream>
#include <stdlib.h>
#include <string>
#include "tree_t.h"


int charCheck(std::string someText){
    unsigned int i = 0;

    for(i = 0; i < someText.length(); i++)
    {
        if (isdigit(someText[i]) || someText[i] == '-')
        {
            
        } else {
            return 1;
        }
    }
    return 0;

}

int main(int argc, char const *argv[])
{
    std::string inString = "";
    int doneFlag = 0;
    int input = 0;
    tree_t<int> myTree;

    while (doneFlag == 0){
        std::cin >> inString;

        if (inString == "END"){
            doneFlag = 1;
        } else {
            if (!charCheck(inString)) {
                input = atoi(inString.c_str());
                myTree.add(input);
            }
        }
    }

    myTree.print();

    return 0;
}