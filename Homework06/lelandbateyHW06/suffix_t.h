#include <iostream>
#include "trie_n.h"
#pragma once


class trie_t
{
protected:
    trie_n* root;

private:
    virtual void insert(std::string s, int word, int line, int page){ std::cout << "Yeeaaaaah, so there's not actually an insert function here yet..." << std::endl;};
    // virtual void search(std::string s){std::cout << "ummm... So there's not a search function either..." << std::endl;};

    std::vector<wordPos_ts*> search(std::string s){
        trie_n* mNode = root;

        for (int i = 0; i < s.size(); ++i){
            if (mNode->isValid(s[i])){
                mNode = mNode->getChild(s[i]);
            }
        }
        resultsPrint(mNode->getLoc(),s);
        return mNode->getLoc();

    };

    void resultsPrint(std::vector<wordPos_ts*> vec, std::string s){
        if (vec.size()){
            for (int i = 0; i < vec.size(); ++i){
                std::cout << "String being searched for: " << s << std::endl;
                std::cout << "\tPosition #" << i << std::endl;
                std::cout << "\t Word: " << vec[i]->word  << std::endl;
                std::cout << "\t Line: " << vec[i]->line  << std::endl;
                std::cout << "\t Page: " << vec[i]->page  << std::endl;
            }
        }
    }

public:
    trie_t(){
        root = new trie_n();
    };

    void add(std::string str, int word, int line, int page){
        insert(str, word, line, page);
    }

    std::vector<wordPos_ts*> find(std::string s){
        return search(s);
    }

    void print(){
        root->print();
    }
    
};

class suffix_t: public trie_t{
private:
    virtual void insert(std::string s, int word, int line, int page){
        // Suffix insert
        trie_n* mNode = root;

        // std::cout << s << std::endl;
        // std::cout << s.size() << std::endl;

        for (int i = 0; i < s.size(); ++i){
            mNode = root;
            for (int k = i; k < s.size(); ++k){
                // std::cout << s[k] << std::endl;
                if (mNode->isValid(s[k])){
                    mNode = mNode->getChild(s[k]);
                    mNode->storeWordLoc(word, line, page);
                }
            }
            // std::cout << "" << std::endl;

        }
    };

    // virtual void search(std::string s){
    //     trie_n* mNode = root;

    //     for (int i = 0; i < s.size(); ++i){
    //         if (mNode->isValid(s[i])){
    //             mNode = mNode->getChild(s[i]);
    //         }
    //     }

    // };
};

class prefix_t: public trie_t{
private:
    virtual void insert(std::string s, int word, int line, int page){
        
    };
    // virtual void search(std::string s){

    // };
};

