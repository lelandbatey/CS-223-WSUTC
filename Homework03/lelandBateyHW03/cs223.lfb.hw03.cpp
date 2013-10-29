

#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 1
#endif

#include <iostream>
#include <string>
#include <vector>
#include "lfbLib.h"
#include "avl_tree_t.h"

// template <class MT>
class tmp_c
{

public:
    // tmp_c(arguments);
    // ~tmp_c();

    int value;
    tmp_c() {
        value = 1;
    };

    tmp_c(int val){
        value = val;
    };
    
    int getVal(){
        return value;
    }

    friend bool operator ==(const tmp_c &tc1, const tmp_c &tc2) {
        return (tc1.value == tc2.value);
    }

    friend bool operator < (const tmp_c &tc1, const tmp_c &tc2) {
        return (tc1.value < tc2.value);
    }

    friend bool operator > (const tmp_c &tc1, const tmp_c &tc2) {
        return (tc1.value > tc2.value);
    }
};


int main(int argc, char const *argv[]) {
    
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << argv[i] << " " << i << std::endl;
    // };


    tmp_c* tempCont;
    tree_t<tmp_c*> myAVL;
    // tree_t<tmp_c*> bst;
    for (int i = 1; i < argc; ++i) {
        tempCont = new tmp_c;

        tempCont->value = int(strToDub(std::string(argv[i])));
        // std::cout << tempCont->value << std::endl;
        myAVL.add(tempCont);
    }

    myAVL.print();

    // std::string thing;
    // std::cin >> thing;

    return 0;
}


