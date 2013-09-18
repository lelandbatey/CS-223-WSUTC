#include "tree.h"
#include "iostream"
#include "stdio.h"
#include "string"

#ifndef NULL
#define NULL 0
#endif

using namespace std;

int charCheck(string someText){
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
    string inputString = "";
    int doneFlag = 0;
    int input = 0;
    lbtree myTree;


    while (doneFlag == 0){
        cin >> inputString;

        if (inputString == "END")
        {
            doneFlag = 1;
        } else { // If they enter something that's not END

            if (!charCheck(inputString)){ // If there are no non-number characters in the string, then we add it to the tree.
                input = atoi(inputString.c_str());
                myTree.add(input);
            }

        }
    }

    return 0;
}

