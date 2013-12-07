#include <iostream>
#include <vector>
#include <string>
#include "suffix_t.h"
#include "lfblib.h"

/*
Something I hadn't realized while writing this was that one of the bonus goals
of the program was "...don’t store the entire file for printing pre- and post-
words after the pattern." This is actually not **that** hard to do, as one of
my classmates explained.

The basic idea is you read things into suffix tree, then you go back and re-
process the file when you have to print the information that their looking
for.

## Pseudocode

    buildSuffixTree():
        
        while(!fileIsEmpty):
            line = getline(fileName)
            linecount++

            std::stringstream ss(line);
            // http://stackoverflow.com/a/11719617
            while(std::getline(ss,word,' '){
                wordCount++;
                if (!disallowedWordMap[word]){
                    pageNum = linecount/20; // Integer division of number of lines by the number of lines-per-page (20 by default)
                    suffixTree.insert(word,wordCount,linecount,pageNum);
                }
            }

*/

void readIntoTrees(std::string fileName, suffix_t* sTree){ // prefix_t pTree){
    int totalLines = getLines(fileName);
    std::ifstream input(fileName.c_str());

    std::string line;
    std::vector<std::string> wLine;

    int i = 0;
    int pageNum = 0;
    while (i < totalLines){
        getline(input, line, '\n');
        i++;

        wLine = split(line,' ');
        for (int k = 0; k < wLine.size(); ++k){
            pageNum = (i/20);
            sTree->add(wLine[k],k,i,pageNum);
        }

    }
}






