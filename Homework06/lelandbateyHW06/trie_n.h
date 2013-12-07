#include <vector>
#include <string>
#include <iostream>

#ifndef __CHILDRENAMOUNT__
#define __CHILDRENAMOUNT__ 35
#endif

typedef struct {
    int word, line, page;
} wordPos_ts;



class trie_n
{

private:

    std::vector<wordPos_ts*> wordLoc;

    trie_n* children[__CHILDRENAMOUNT__]; // It's 35 because of 26 letters in the alphabet 
                          // as well as the numbers 0-9

public:
    trie_n(){
        // Sadly, it's the only thing I could think of initialize the whole thing to 0
        for (int i = 0; i < __CHILDRENAMOUNT__; ++i){
            children[i] = 0;
        }

    };
    // ~trie_n();

    trie_n* getChild(char c){
    // Given a character, returns the correct child node (if given a valid character).
    //
    // Assumes that the character will be lowercase. Additionally, the
    // 'map' from characters to positions in the array is:
    //      lowercase a - z:
    //          Array indices 0 - 25
    //      numbers 0 - 9:
    //          array indices 26 - 35

        trie_n* nulTrie = 0;

        if (c < 'z' && c > 'a'){
            if (children[c-'a'] == 0){ // if it's un-initialized
                children[c-'a'] = new trie_n();
                return children[c-'a'];
            }
            return children[c-'a'];
        }

        if (c > '0' && c < '9'){
            // The '22' seems like a magic number. However, it's because we
            // want to get 0-9 to be in the 26-35 position. Since '0' is 48,
            // we subtract 22 to make it begin at 26.
            if (!children[c-22]){
                children[c-22] = new trie_n();
                return children[c-22];
            }
            return children[c-22];
        }

        return nulTrie; // Return a null point in the event of an invalid character
    }

    void storeWordLoc(int w, int l, int p){
        wordPos_ts* tmpLoc = new wordPos_ts;
        tmpLoc->word = w;
        tmpLoc->line = l;
        tmpLoc->page = p;

        wordLoc.push_back(tmpLoc);
    }

    std::vector<wordPos_ts*> getLoc(){
        return wordLoc;
    }

    void print(){
        if (wordLoc.size() > 0){
            for (int i = 0; i < wordLoc.size(); ++i){
                std::cout << "Location #" << i << "" << std::endl;
                std::cout << "  Word: " << wordLoc[i]->word << std::endl;
                std::cout << "  Line: " << wordLoc[i]->line << std::endl;
                std::cout << "  Page: " << wordLoc[i]->page << std::endl;

            }
        }
        for (int i = 0; i < 36; ++i){
            if (children[i]){
                std::cout << "Origin : " << this << std::endl;
                std::cout << "Char   : " << schemeToChar(i) << std::endl;
                std::cout << "Address: " << children[i] << std::endl;
            }
            if (children[i]){
                children[i]->print();
            };
        };
    };

    bool isValid(char c){
        if (c > 'a' && c < 'z'){
            return true;
        } else if (c > '0' && c < '9') {
            return true;
        } else {
            return false;
        }
    }

    // Given a number, converts it back to the proper charachter.
    // Useful in the printing function
    char schemeToChar(int inVal){
        if (inVal >= 0 && inVal <= 25){
            return (char)(inVal+'a');
        } else if (inVal >= 26 && inVal <= 35){
            return (char)(inVal+22);
        }
    }
    
};


