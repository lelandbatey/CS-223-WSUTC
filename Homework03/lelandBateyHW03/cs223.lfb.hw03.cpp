

#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef LIGHT_DEBUG
#define LIGHT_DEBUG 0
#endif

#include <iostream>
#include <string>
#include <vector>
#include "lfbLib.h"
#include "avl_tree_t.h"
#include "readFileLines.cpp"
#include "names_c.h"

// template <class MT>
// class tmp_c
// {

// public:
//     // tmp_c(arguments);
//     // ~tmp_c();

//     int value;
//     tmp_c() {
//         value = 1;
//     };

//     tmp_c(int val){
//         value = val;
//     };
    
//     int getVal(){
//         return value;
//     }

//     friend bool operator ==(const tmp_c &tc1, const tmp_c &tc2) {
//         return (tc1.value == tc2.value);
//     }

//     friend bool operator < (const tmp_c &tc1, const tmp_c &tc2) {
//         return (tc1.value < tc2.value);
//     }

//     friend bool operator > (const tmp_c &tc1, const tmp_c &tc2) {
//         return (tc1.value > tc2.value);
//     }
// };


int main(int argc, char const *argv[]) {
    
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << argv[i] << " " << i << std::endl;
    // };


    // tmp_c* tempCont;
    // tree_t<name_c*> myAVL;
    // // tree_t<tmp_c*> bst;
    // for (int i = 1; i < argc; ++i) {
    //     tempCont = new tmp_c;

    //     tempCont->value = int(strToDub(std::string(argv[i])));
    //     // std::cout << tempCont->value << std::endl;
    //     myAVL.add(tempCont);
    // }

    if (argc < 2){
        std::cout << "Dude, input a file name. Seriously... :/" << std::endl;
        return 0;
    }

    tree_t<name_c*> myAVL;
    name_c* tempName;
    std::vector<std::string> nameList = getNames(std::string(argv[1]));

    // std::cout << sizeof(nameList) << std::endl;

    for (unsigned int i = 0; i < nameList.size(); ++i) {
        if (strToBool(nameList[i])) {
            
            if (DEBUG) {
                std::cout << i << ' ';
                std::cout << nameList[i] << std::endl;
            }

            tempName = new name_c();
            tempName->setName(nameList[i]);
            
            if (DEBUG) {
                std::cout << "-- " << tempName->getVal() << std::endl;
                std::cout << "-- " << tempName->getNumName() << std::endl;
            }

            myAVL.add(tempName);

        }
    }

    std::cout << " Get tree height: " << myAVL.getTreeHeight() << std::endl;
    myAVL.print();

    // std::string thing;
    // std::cin >> thing;

    return 0;
}


