#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

#include "buildPointsFromFile.cpp"
#include "kd_tree.h"
#include "kd_point.h"



kd_point* linSearch(kd_point** pntList, kd_point* search_point, int* plSize){
    kd_point* nearest;
    double dist = 10000;

    for (int i = 0; i < (*plSize); ++i){
        if (oCalcDistance(search_point, pntList[i]) < dist){
            dist = oCalcDistance(search_point, pntList[i]);
            nearest = pntList[i];
        }
    }
    return nearest;
}



int main(int argc, char const *argv[])
{
    if (argc < 3) {
        std::cout << "usage: peptides databaseFile observedListFile" << std::endl;
        return 1;
    }

    int* plSize = new int(0);
    kd_point** pntList = getPointList(std::string(argv[1]), plSize);

    int* olSize = new int(0);
    kd_point** opList = getObservedList(std::string(argv[2]), olSize);


    kd_tree mTree;

    mTree.build(pntList, *plSize);

    std::cout << "Observed ID, Peptide, NET, Mass, Observed NET, Observed Mass" << std::endl;
    for (int i = 0; i < *olSize; ++i){
        mTree.search(opList[i]);
    }





    return 0;
}

