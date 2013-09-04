#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
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
    stringstream ss;

    while (doneFlag == 0){
        cin >> inputString;

        if (inputString == "END")
        {
            doneFlag = 1;
        } else { // If they enter something that's not END

            // Here we do the "stream-dropthrough". If the string can't be made
            // into a valid integer, then the integer that it's being assigned to
            // will retain it's old value.
            ss << inputString;
            ss >> input;

            if (input != SENTINEL) // If the user's entered a valid integer, add that value to the tree.
            {
                myTree.add(input);
            }
        }
    }

    myTree.depthFirstSearch();
    myTree.breadthFirstSearch();

    return 0;
}

