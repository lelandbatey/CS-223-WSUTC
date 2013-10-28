

#ifndef DEBUG
#define DEBUG 1
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
        // std::cout << "  Checking Equality of two containers." << std::endl;
        // std::cout << "  Container 1: " << tc1.value << std::endl;
        // std::cout << "  Container 2: " << tc2.value << std::endl;
        // std::cout << "  Truth Value: " << (tc1.value == tc2.value) << std::endl;
        return (tc1.value == tc2.value);
    }

    friend bool operator < (const tmp_c &tc1, const tmp_c &tc2) {
        // std::cout << "  Checking 1 less than 2" << std::endl;
        // std::cout << "  Container 1: " << tc1.value << std::endl;
        // std::cout << "  Container 2: " << tc2.value << std::endl;
        // std::cout << "  Truth Value: " << (tc1.value < tc1.value) << std::endl;
        return (tc1.value < tc2.value);
    }

    friend bool operator > (const tmp_c &tc1, const tmp_c &tc2) {
        // std::cout << "  Checking 1 greater than 2" << std::endl;
        // std::cout << "  Container 1: " << tc1.value << std::endl;
        // std::cout << "  Container 2: " << tc2.value << std::endl;
        // std::cout << "  Truth Value: " << (tc1.value < tc1.value) << std::endl;
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


