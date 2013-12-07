#include <iostream>
#include <string>
#include <vector>

#include "lfblib.h"
#include "fileReader.h"
#include "suffix_t.h"

// #ifndef DEBUG
#define DEBUG 1
// #endif

int main(int argc, char const *argv[])
{
    if (argc < 2){
        std::cout << "Novel file not given. Exiting." << std::endl;
        return 0;
    }

    suffix_t myTree;

    readIntoTrees(std::string("lorem_ipsum_novel.txt"),&myTree);

    // myTree.add(std::string("what"),1,1,1);
    // myTree.add(std::string("is"),2,1,1);
    // myTree.add(std::string("going"),3,1,1);

    // if (DEBUG){
    //     myTree.print();
    // }

    myTree.find(std::string("g"));
    myTree.find(std::string("tet"));
    // myTree.find(std::string("i"));

    // std::cout <<  << std::endl;

    std::string s;
    // std::cin >> s;

    std::string input;
    std::string otherIn;
    bool doneFlag = false;

    // Get input loop and execute commands

    while (!doneFlag) {
        input = "";

        // So, you may ask, why is it that we're not just using good ol'
        // "std::cin >> somevar" to get what we need right here?
        //
        // I'll tell you why: because doing it that way for anything but the
        // most trivial of input sucks giant purple donkey dicks. Seriously,
        // though, we get the whole line so we can break it up all nice and
        // neet however we want. In this case, we want everything before the
        // first space on the line of input to be the "command" verb, and
        // everything after that (if anything) to be modifiers to that command
        // verb.
        std::getline(std::cin, input);
        otherIn = getAfter(input," "); // The command verb
        input = getBefore(input," "); // the command modifiers

        input = strUpper(input);
        otherIn = strUpper(otherIn);
        if (input == "EXIT") {
            
            std::cout << "Hope you found what you need!" << std::endl;
            return 0;
        } else if (input == "PREFIX"){
            
        }
    }

    return 0;
}





