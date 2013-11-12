#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#ifndef DEBUG
#define DEBUG 1
#endif
#include "../buildPointsFromFile.cpp"
#include "../kd_tree.h"
#include "../kd_point.h"


int countPnts(kd_point** pList, int initSize){
    int toReturn = 0;
    for (int i = 0; i < initSize; ++i){
        if (pList[i]->mass && pList[i]->NET) {
            toReturn++;
        }
    }
}


int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cout << "Not enough arguments." << std::endl;
        return 1;
    } else {
        for (int i = 0; i < argc; ++i){
            std::cout << i << " " << argv[i] << std::endl;
        }
    }

    int* plSize = new int(0);
    kd_point** pntList = getPointList(std::string(argv[1]), plSize);

    kd_tree mTree;

    mTree.build(pntList, *plSize);

    mTree.bfp();
    return 0;
}