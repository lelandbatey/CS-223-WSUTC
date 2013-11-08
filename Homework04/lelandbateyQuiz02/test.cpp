#include <algorithm>
#include <unistd.h>
#include <iostream>
// #include "kd_point.h"
#include "kd_node.h"

#ifndef MAX_SIZE
#define MAX_SIZE 200000
#endif

void prntPnt(kd_point* pnt){
    // std::cout << "Point Addr: " << pnt << std::endl;
    // std::cout << "   Mass : " << pnt->mass << std::endl;
    // std::cout << "   NET  : " << pnt->NET  << std::endl;
    std::cout << pnt->mass << "," << pnt->NET << std::endl;
}

int divUp(int num, int den){
    return int(num/den) + int(bool(num%den));
}


bool (*compCheck[2])(kd_point*,kd_point*);

void printDiv(int begin, int end, int k, int i, kd_point** pList, kd_node* node ){
    // sleep(1);
    int mid = (end-begin)/2;

    // std::cout << "\nBegin: " << begin << std::endl;
    // std::cout << "End  : " << end << std::endl;
    // std::cout << "Mid  : " << mid << std::endl;
    // std::cout << "Pos  : " << mid+begin << std::endl;
    i = (i+1) % k;


    std::sort(&pList[begin], &pList[end], compCheck[i]);

    if (end <= begin){
        // std::cout << "This should not be happening..." << std::endl;
        return;
    } else if (end - begin == 1) {
        // std::cout << "  Only one item" << std::endl;
        node = new kd_node(pList[begin]);
        prntPnt(pList[begin]);
    } else if (end-begin > 1) {
        
        node = new kd_node(pList[begin+mid]);
        prntPnt(pList[begin+mid]);
        
        printDiv(begin, begin+mid, k, i, pList, node->left);
        printDiv(begin+mid+1, end, k, i, pList, node->right);
    } else {
        std::cout << "SOMETHIN GONE WRONG!" << std::endl;
        std::cout << begin << std::endl;
        std::cout << end << std::endl;
        std::cout << pList << std::endl;
    }
}



int main(int argc, char const *argv[]) {
    
    compCheck[0] = &compMass;
    compCheck[1] = &compNET;

    kd_point* pntArray[MAX_SIZE];

    kd_node* root = 0;


    for (int i = 0; i < MAX_SIZE; ++i){
        pntArray[i] = new kd_point( ((double)(i+1)),((double)(2*MAX_SIZE-i)) );
        // pntArray[i] = new kd_point( ((double)(i+1)),((double)(i+1)) );
    }

    std::cout << "Begin priting!" << std::endl;
    printDiv(int(0), MAX_SIZE, 2, 1, pntArray, root );
    // for (int i = 0; i < MAX_SIZE; ++i){
    //     std::cout << "Point: "<< i << std::endl;
    //     std::cout << "   Mass : " << pntArray[i]->mass << std::endl;
    //     std::cout << "   NET  : " << pntArray[i]->NET  << std::endl;
    // }

    // std::sort(&pntArray[0], &pntArray[MAX_SIZE], compCheck[1]);
    // // std::sort(&pntArray[0], &pntArray[3], compCheck[0]);


    // std::cout << "--Print Array--" << std::endl;
    // for (int i = 0; i < MAX_SIZE; ++i){
    //     std::cout << "Point: "<< i << std::endl;
    //     std::cout << "   Mass : " << pntArray[i]->mass << std::endl;
    //     std::cout << "   NET  : " << pntArray[i]->NET  << std::endl;
    // }



    // kd_point pnt1(5,2);
    // kd_point pnt2;

    // pnt2 = pnt1;

    // pnt2.mass = 3;

    // std::cout << "pnt1: " << pnt1.NET << "," << pnt1.mass << std::endl;
    // std::cout << "pnt2: " << pnt2.NET << "," << pnt2.mass << std::endl;

    return 0;
}



