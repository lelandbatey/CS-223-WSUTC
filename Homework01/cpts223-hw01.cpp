#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map> // Dictionary/map
#include "tree.h"
#include "queue.h"

using namespace std;
// Leland Batey
// Cpts 223

#define SENTINEL 31415 // This will be the sentinel value for numbers read from stdin.
// Explanation of the above:

// So it turns out that if you initiallize an `int` to some number, then try
// to assign a non-int value to that int from a stream, it will just ignore
// the value from the stream and maintain it's initial value. This allows me
// to (in a ghetto way) deal with non-integer input.

// Used to check if 
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


int recursePrint(treeNode *node){ // Prints out all the numbers in order.
    if (node->leftChild){
        recursePrint(node->leftChild);
    }
    printf("%d\n", node->value );
    if (node->rightChild){
        recursePrint(node->rightChild);
    }
    return 0;
}

int main()
{
    int doneFlag = 0; // Will be used to stop the while loop.
    int input=SENTINEL;
    string inputString = "";
    tree myTree;
    

    while (doneFlag == 0){
        cin >> inputString;

        if (inputString == "END")
        {
            doneFlag = 1;
        } else { // If they enter something that's not END

            if (!charCheck(inputString)){ // If there are no non-number characters in the string, then we add it to the tree.
                input = atoi(inputString.c_str());
                // cout << input << endl;
                myTree.add(input);
            }

        }
    }

    myTree.setDepth();
    myTree.findMaxWidth();
    // myTree.print();
    // myTree.depthFirstSearch();
    // myTree.breadthFirstSearch();

    // myTree.print();

    return 0;
}

