#include <algorithm>
#include <iostream>
#include "kd_node.h"


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


class kd_tree
{
private:
    kd_node* root;
public:
    kd_tree(){
        root = 0;
    };
    // ~kd_tree();

    
};

