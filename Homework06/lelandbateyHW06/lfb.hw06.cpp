#include <iostream>
#include <string>
#include <vector>

#include "lfblib.h"
#include "fileReader.h"
#include "suffix_t.h"

// #ifndef DEBUG
#define DEBUG 0
// #endif

int main(int argc, char const *argv[])
{
    if (argc < 2){
        std::cout << "Novel file not given. Exiting." << std::endl;
        return 0;
    }

    suffix_t sTree;
    prefix_t pTree;
    std::string fileName = std::string(argv[1]);

    // fileName = "lorem_ipsum_novel.txt";

    readIntoTrees(fileName,&sTree,&pTree);

    std::string s;
    // std::cin >> s;

    std::string input;
    std::string otherIn;
    bool doneFlag = false;


    if (DEBUG){
        std::map<std::string,int>* badWords = buildCommonWordsMap(std::string("commonWords.txt"));
        // std::cout << badWords->count(cleanString(strLower(std::string("a")))) << std::endl;

        std::cout << badWords << std::endl;
        std::cout << badWords->size() << std::endl;
        
    }


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

        input = strLower(input);
        otherIn = strLower(otherIn);

        // std::cout << "'" <<  input << "'" << std::endl;
        // std::cout << "'" << otherIn << "'" << std::endl;

        if (input == "exit") {
            
            std::cout << "Hope you found what you need!" << std::endl;
            return 0;
        } else if (input == "prefix"){
            printTreeResults(pTree.find(otherIn), otherIn, fileName);
            // pTree.find(otherIn);
        } else if (input == "suffix"){
            printTreeResults(sTree.find(otherIn), otherIn, fileName);
            // sTree.find(otherIn);
        }
    }

    return 0;
}





