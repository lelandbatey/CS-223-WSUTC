#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "readFileLines.cpp"
// #include "kd_tree.h"
#include "kd_point.h"

// #ifndef DEBUG
#define DEBUG 1
// #endif

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        std::cout << "Not enough arguments." << std::endl;
        return 1;
    } else {
        for (int i = 0; i < argc; ++i){
            std::cout << i << " " << argv[i] << std::endl;
        }
    }

    // std::vector<kd_point*> pntVect = getPointList(std::string(argv[1]));
    kd_point** pntList = getPointList(std::string(argv[1]));



    return 0;
}

