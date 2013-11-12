#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <unistd.h>
#ifndef _BEGIN_DIM_
#define _BEGIN_DIM_ 1
#endif

#ifndef _DIMS_
#define _DIMS_ 2
#endif
#include "kd_node.h"




class kd_tree
{
private:

    kd_node* root;
    bool (*compCheck[2])(kd_point*,kd_point*);
    bool (*oCompCheck[2])(kd_point*,kd_point*);
    double (*sphereCheck[2])(kd_point*,kd_point*);

    void prntPnt(kd_point* pnt){
        // std::cout << "Point Addr: " << pnt << std::endl;
        // std::cout << "   Mass : " << pnt->mass << std::endl;
        // std::cout << "   NET  : " << pnt->NET  << std::endl;
        std::cout << pnt->peptide << "," << pnt->mass << "," << pnt->NET << std::endl;
    }

    // Recursive building of our kd-tree.
    void buildTree(int begin, int end, int k, int i, kd_point** pList, kd_node*& node ){
        // sleep(1);
        int mid = (end-begin)/2;

        // std::cout << "\nBegin: " << begin << std::endl;
        // std::cout << "End  : " << end << std::endl;
        // std::cout << "Mid  : " << mid << std::endl;
        // std::cout << "Pos  : " << mid+begin << std::endl;

        std::cout << "A: " << node << std::endl;

        i = (i+1) % k;


        std::sort(&pList[begin], &pList[end], compCheck[i]);

        if (end <= begin){
            // std::cout << "This should not be happening..." << std::endl;
            return;
        } else if (end - begin == 1) {
            // std::cout << "  Only one item" << std::endl;
            // std::cout << "Assign start" << std::endl;
            node = new kd_node(pList[begin],i);
            prntPnt(pList[begin]);
        } else if (end-begin > 1) {
            
            // std::cout << "Assign mid" << std::endl;
            node = new kd_node(pList[begin+mid],i);
            std::cout << "A: " << node << std::endl;

            prntPnt(pList[begin+mid]);
            
            buildTree(begin, begin+mid, k, i, pList, node->getLeft());
            buildTree(begin+mid+1, end, k, i, pList, node->getRight());
        } else {
            std::cout << "SOMETHIN GONE WRONG!" << std::endl;
            std::cout << begin << std::endl;
            std::cout << end << std::endl;
            std::cout << pList << std::endl;
        }
    }

    void nnSearch(kd_node* node, kd_point* sPoint){
        kd_point* nn;
        bool done = false;
        int k = _BEGIN_DIM_;

        std::stack<kd_node*> nStack = loopTreeSearch(node, sPoint);


        std::cout << "Top: " << nStack.top() << std::endl;
        std::cout << "TopVal: " << nStack.top()->getVal() << std::endl;
        nn = nStack.top()->getVal();
        nStack.pop();

        std::cout << "Node: " << node << std::endl;
        

        double bestDist = 0;
        bestDist = oCalcDistance(sPoint, nn);



        done = false;
        while (!done){
            if (!nStack.empty()){
                node = nStack.top();
                nStack.pop();
            } else {
                std::cout << "Stack is empty!" << std::endl;
                done = true;
                continue;
            }

            // See if it lies inside our hypersphere radius

            if (isInsideHyperSphere( bestDist, nn, node->getVal() )){
                std::cout << "This node is in the hypersphere:" << std::endl;
                prntPnt(node->getVal());

                std::stack<kd_node*> checkStack;
                kd_point* potentialNeighbor;
                kd_node* checkNode = node;

                if (oCompCheck[checkNode->getK()](sPoint, checkNode->getVal())){
                    checkStack = loopTreeSearch(checkNode->getRight(), sPoint); // Here we got right instead of left
                } else {
                    checkStack = loopTreeSearch(checkNode->getLeft(), sPoint); // Here we go left isntead of right
                }
                potentialNeighbor = checkStack.top()->getVal();

                if (bestDist > oCalcDistance(sPoint, potentialNeighbor)){
                    bestDist = oCalcDistance(sPoint, potentialNeighbor);
                    nn = potentialNeighbor;
                    std::cout << "Found a new nearest neighbor!" << std::endl;
                }
            }
        }
        std::cout << std::setprecision(5) << bestDist << std::endl;
        std::cout << "Nearest neighbor:" << std::endl;
        prntPnt(nn);
        std::cout << "sPoint: " << std::endl;
        std::cout << sPoint->getObservedMass() << "," << sPoint->getObservedNET() << std::endl;
    }

    std::stack<kd_node*> loopTreeSearch(kd_node*& node, kd_point*& sPoint){
        // kd_point* nn;
        bool done = false;
        int k = _BEGIN_DIM_;

        std::stack<kd_node*> nStack;

        while (!done){
            k = (k+1) % _DIMS_;
            if (node == NULL){
                done = true;
                continue;
            }
            if (node){
                if (oCompCheck[k](sPoint,node->getVal())){ // Then the search_node is smaller than the current node.
                    nStack.push(node);
                    node = node->getLeft();
                } else if (!oCompCheck[k](sPoint,node->getVal())){ // search_node is larger than the current node.
                    nStack.push(node);
                    node = node->getRight();
                }
            }
        }
        return nStack;
    }

    void recSearch(kd_node*& node, kd_point*& sPoint, kd_point*& nn, int k){
        k = (k+1) % _DIMS_;

        // bool foundLeaf = false


        if (oCompCheck[k](sPoint, node->getVal())){ // sPoint smaller, go left
            if (node->getLeft()){
                recSearch(node->getLeft(), sPoint, nn, k);
            } else {
                if (oCalcDistance(sPoint, node->getVal()) < oCalcDistance(sPoint, nn)){
                    nn = node->getVal();
                }
                return;
            }
        } else { // sPoint larger, go right.
            if (node->getRight()){
                recSearch(node->getRight(), sPoint, nn, k);
            } else {
                if (oCalcDistance(sPoint, node->getVal()) < oCalcDistance(sPoint, nn)){
                    nn = node->getVal();
                }
                return;
            }
        }

        // If the cartesian distance is less, then current node the new nearest neighbor
        if (oCalcDistance(sPoint, node->getVal()) < oCalcDistance(sPoint, nn)){
            nn = node->getVal();
        }

        // If there's any possibility that there could be nodes in another
        // fork of the subtree, then we explore that as well.
        if (sphereCheck[k](sPoint, node->getVal()) < oCalcDistance(sPoint, nn)){
            if ( oCalcDistance(sPoint, node->getVal()) ){// spoint smaller, but we check the other direction (right)
                if (node->getLeft()){
                    recSearch(node->getRight(), sPoint, nn, k);
                }
            } else {
                if (node->getRight()){
                    recSearch(node->getLeft(), sPoint, nn, k);
                }
            }
        }

        

        return;
    }
public:
    kd_tree(){
        root = 0;
        // Initialize our array of comparison functions.
        // These functions are initially declared in kd_point.h
        compCheck[0] = &compMass;
        compCheck[1] = &compNET;
        oCompCheck[0] = &oCompMass;
        oCompCheck[1] = &oCompNET;
        sphereCheck[0] = &distMass;
        sphereCheck[1] = &distNET;
    };

    void build(kd_point** pList, int max_size ){
        int dimensions = 2;
        int startDim = _BEGIN_DIM_; // Kinda a magic number. We actually want it to be 0, but since it's immediately messed with, we pass in 1 so that after being altered it will be 0.
        buildTree(0, max_size, dimensions, startDim, pList, root );
    }

    // ~kd_tree();

    void search(kd_point* sPoint ){
        // nnSearch(root, sPoint);
        kd_point* nn = root->getVal();
        recSearch(root, sPoint, nn, _BEGIN_DIM_);
        std::cout << "Nearest neighbor:" << std::endl;
        prntPnt(nn);
    }

    void bfp(){

        std::queue<kd_node*> Q;

        std::cout << "Root: " << root << std::endl;

        kd_node* node;
        kd_node* markNode;
        markNode = root->getLeft();

        int i = 0;
        bool search = false;

        // std::cout << "Root info: " << std::endl;
        // prntNodeInfo(root);
        Q.push(root);

        while (!Q.empty()){
            node = Q.front();
            Q.pop();


            if ( node == markNode || search == true) {
                
                if (node==markNode && search == false) {
                    i++;                    
                }

                search = true;
                if (node->getLeft()) {
                    markNode = node->getLeft();
                    // i++;
                    search = false;
                } else if (node->getRight()){
                    markNode = node->getRight();
                    // i++;
                    search = false;
                } else {
                    // if (Q.front()) {
                    //     i++;
                    //     markNode = Q.front();
                    // } else {
                    //     // i++;
                    // }
                }
            }
            if (node) {
                std::cout << std::endl;
                // std::cout << "  Level: " << i << std::endl;
                // std::cout << "  Node : " << node << std::endl;
                // std::cout << "  L    : " << node->getLeft()<< std::endl;
                // std::cout << "  R    : " << node->getRight() << std::endl;
                prntPnt(node->getVal());
            }
            // std::cout << "," << getBalance(node) << std::endl;
            // prntNodeInfo(node, true);
            // prntNodeInfo(markNode);

            if (node->getLeft()) {
                Q.push(node->getLeft());
            }
            if (node->getRight()) {
                Q.push(node->getRight());
            }
        } 
    }
    
};

