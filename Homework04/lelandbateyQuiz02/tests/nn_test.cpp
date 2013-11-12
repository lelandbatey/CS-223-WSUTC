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

kd_point* linSearch(kd_point** pntList, kd_point* search_point, int* plSize){
    kd_point* nearest;
    double dist = 10000;

    for (int i = 0; i < (*plSize); ++i){
        if (oCalcDistance(search_point, pntList[i]) < dist){
            dist = oCalcDistance(search_point, pntList[i]);
            nearest = pntList[i];
        }
    }

    std::cout << "Nearest (linear search): " << std::endl;
    std::cout << "  " << nearest->getMass() << "," << nearest->getNET() << std::endl;

    return nearest;
}

int main(int argc, char const *argv[])
{
    int* plSize = new int(0);
    kd_point** pntList = getPointList(std::string("../peptideDatabase.csv"), plSize);

    kd_tree mTree;
    mTree.build(pntList, *plSize);

    // ID,NET,Mass
    // 0,0.149476528,544.2968806
    kd_point* search_point = new kd_point();
    search_point->setObservedMass(544.2968806);
    search_point->setObservedNET(0.149476528);
    search_point->setID(0);

    // 1,0.148264542,609.2944385

    kd_point* sp = new kd_point();
    sp->setObservedMass(609.2944385);
    sp->setObservedNET(0.148264542);
    sp->setID(1);


    mTree.search(search_point);
    mTree.search(sp);


    linSearch(pntList, search_point, plSize);
    linSearch(pntList, sp, plSize);

    return 0;
}
