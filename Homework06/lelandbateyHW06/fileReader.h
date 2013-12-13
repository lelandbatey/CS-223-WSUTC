#include <iostream>
#include <vector>
#include <string>
#include <map>
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

std::string cleanString(std::string s){
    std::string finalString;
    // std::cout << s << std::endl;
    char c;
    for (int i = 0; i < s.size(); ++i){
        c = s[i];
        if (c >= 'a' && c <= 'z'){
            finalString += c;
        } else if (c >= '0' && c <= '9') {
            finalString += c;
        }
    }
    // std::cout << finalString << std::endl;
    return finalString;
}


std::map<std::string,int>* buildCommonWordsMap(std::string fileName){

    std::map<std::string,int>* badWordMap = new std::map<std::string,int> ;

    std::map<std::string,int> wordMap;

    int totalLines = getLines(fileName);
    std::ifstream input(fileName.c_str());
    std::string line;

    for (int i = 0; i < totalLines; ++i){
        getline(input, line, '\n');
        // std::cout << "'" << line << "'" << std::endl;
        (*badWordMap)[line] = 1;
    }
    input.close();
    // std::cout << badWordMap << std::endl;
    // std::cout << badWordMap->size() << std::endl;
    return badWordMap;
}


void readIntoTrees(std::string fileName, suffix_t* sTree, prefix_t* pTree){
    int totalLines = getLines(fileName);
    std::ifstream input(fileName.c_str());

    std::string line;
    std::vector<std::string> wLine;

    std::map<std::string,int>* badWords = buildCommonWordsMap(std::string("commonWords.txt"));

    int i = 0;
    int pageNum = 0;
    while (i < totalLines){
        getline(input, line, '\n');

        wLine = split(line,' ');
        for (int k = 0; k < wLine.size(); ++k){
            pageNum = (i/20)+1; // PageNum has to start at 1
            
            if (!badWords->count( cleanString(strLower(wLine[k])) )){ // If the word to be inserted isn't one of the top 100 most common.
                // Why the "(i%20)"?
                // Because the line number is relative to the page number, it's not monotonically increasing.
                sTree->add(strLower(wLine[k]),k, (i%20),pageNum);
                pTree->add(strLower(wLine[k]),k, (i%20),pageNum);
            }
        }
        i++;

    }
    input.close();
}

void printTreeResults(std::vector<wordPos_ts*> vec, std::string s, std::string fileName){
    
    int totalLines = getLines(fileName);
    std::ifstream input;//(fileName.c_str());

    std::string line;
    std::vector<std::string> wLine;

    int i = 0;
    int pageNum = 0;

    int totalLineNum = 0;

    std::cout << std::endl << s << " found on:" << std::endl << std::endl;
    for (int x = 0; x < vec.size(); ++x){

        std::cout << "\tPage: " << vec[x]->page << " Line: " << vec[x]->line << std::endl << std::endl;
        
        totalLineNum = ((vec[x]->page - 1) * 20) + vec[x]->line;

        input.open(fileName.c_str());
        line = "";
        wLine.clear();

        i = 0;
        pageNum = 0;

        while (i < totalLines){
            getline(input, line, '\n');

            if (i == totalLineNum){
                wLine = split(line,' ');
                std::cout << "\t\t... ";
                
                for (int k = 0; k < wLine.size(); ++k){
                    if ( (vec[x]->word-2) == k){
                        std::cout << wLine[k] << " ";
                    } else if ( (vec[x]->word-1) == k){
                        std::cout << wLine[k] << " ";
                    } else if ( (vec[x]->word) == k){
                        std::cout << "\033[1;32m" <<  wLine[k] << "\033[0m ";
                    } else if ( (vec[x]->word+1) == k){
                        std::cout << wLine[k];
                    } else if ( (vec[x]->word+2) == k){
                        std::cout << " " << wLine[k];
                    }
                }
                
                std::cout << "..." << std::endl << std::endl;
                i = totalLines;
                input.close();
            }
            i++;


        }
    }
}






