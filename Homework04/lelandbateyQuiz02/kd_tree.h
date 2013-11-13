#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
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

    // Recursive building of our kd-tree.
    void buildTree(int begin, int end, int k, int i, kd_point** pList, kd_node*& node ){
        int mid = (end-begin)/2;
        i = (i+1) % k;

        std::sort(&pList[begin], &pList[end], compCheck[i]);

        if (end <= begin){
            return;
        } else if (end - begin == 1) {
            // In this case, we have just a single item in our sub-list.
            // Because of that, we just insert it straight away.
            node = new kd_node(pList[begin],i);
        } else if (end - begin > 1) {
            // We've got a sub-array of more than one item, so we insert our
            // middle, then recursively insert the smaller arrays.
            node = new kd_node(pList[begin+mid],i);
            
            buildTree(begin, begin+mid, k, i, pList, node->getLeft());
            buildTree(begin+mid+1, end, k, i, pList, node->getRight());
        } else {
            // If you ever see this, heaven help you.
            std::cout << "SOMETHIN GONE WRONG!" << std::endl;
            std::cout << begin << std::endl;
            std::cout << end << std::endl;
            std::cout << pList << std::endl;
        }
    }

    void recSearch(kd_node*& node, kd_point*& sPoint, kd_point*& nn, int k){
        k = (k+1) % _DIMS_;

        if (node){
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
        } else {
            return;
        }

        // If the Cartesian distance is less, then current node the new nearest neighbor
        if (oCalcDistance(sPoint, node->getVal()) < oCalcDistance(sPoint, nn)){
            nn = node->getVal();
        }

        // If there's any possibility that there could be nodes in another
        // fork of the subtree, then we explore that as well.
        if (sphereCheck[k](sPoint, node->getVal()) <= oCalcDistance(sPoint, nn)){
        // if (isInsideHyperSphere(oCalcDistance(sPoint, nn), nn, node->getVal())) {
            if ( oCompCheck[k](sPoint, node->getVal()) ){// spoint smaller, but
                                                         // we check the other
                                                         // direction (right)
                recSearch(node->getRight(), sPoint, nn, k);
            } else {
                recSearch(node->getLeft(), sPoint, nn, k);
            }
        }

        return;
    }
public:

    // Kinda gross method that given two points, prints the info in the proper
    // format. The first point passed in must be the point with the 'observed
    // data', and the second must be it's nearest-neighbor.
    void formatOutput(kd_point* oPnt, kd_point* pnt){
        std::cout << oPnt->getID() << ", " << pnt->getPep() << ", " <<
        pnt->getNET() << ", " << pnt->getMass() << ", " << oPnt->getObservedNET()
        << ", " << oPnt->getObservedMass() << std::endl;
    }

    // This was used during debugging.
    // Prints the basic info for a point taken from the database.
    void prntPnt(kd_point* pnt){
        std::cout << pnt->getPep() << "," << pnt->getMass() << "," << pnt->getNET() << std::endl;
    }

    kd_tree(){
        root = 0;
        // Initialize our array of comparison functions.
        // These functions are initially declared in kd_point.h
        //
        // There's a nice long explanation for what this is towards the end of
        // kd_point.h
        compCheck[0] = &compMass;
        compCheck[1] = &compNET;
        oCompCheck[0] = &oCompMass;
        oCompCheck[1] = &oCompNET;
        sphereCheck[0] = &distMass;
        sphereCheck[1] = &distNET;
    };

    // Bootstraps the recursive building of the tree.
    void build(kd_point** pList, int max_size ){
        int dimensions = 2;
        int startDim = _BEGIN_DIM_; // Kinda a magic number. We actually want 
                                    // it to be 0, but since it's immediately
                                    // messed with, we pass in 1 so that after
                                    // being altered it will be 0.
        buildTree(0, max_size, dimensions, startDim, pList, root );
    }

    // Bootstraps the recursive search function.
    void search(kd_point* sPoint ){
        kd_point* nn = root->getVal();
        recSearch(root, sPoint, nn, _BEGIN_DIM_);
        formatOutput(sPoint, nn);
    }

    // Prints the entirety of the tree using a breadth-first style 
    void bfp(){
        // Named 'bfp' for 'breadth-first-print'

        std::cout << "Root: " << root << std::endl;

        std::queue<kd_node*> Q;
        kd_node* node;
        kd_node* markNode;
        markNode = root->getLeft();

        int i = 0;
        bool search = false;

        Q.push(root);

        while (!Q.empty()){
            node = Q.front();
            Q.pop();

            // This "search" block assigns the first 'child' as the marker for
            // the next 'level' of the tree.
            if (node == markNode || search == true) {
                
                if (node==markNode && search == false) {
                    i++;                    
                }

                search = true;
                if (node->getLeft()) {
                    markNode = node->getLeft();
                    search = false;
                } else if (node->getRight()){
                    markNode = node->getRight();
                    search = false;
                } else {
                }
            }

            // Print the node, then push it's children onto the stack (if
            // there are any children).
            if (node) {
                std::cout << std::endl;
                prntPnt(node->getVal());
            }
            if (node->getLeft()) {
                Q.push(node->getLeft());
            }
            if (node->getRight()) {
                Q.push(node->getRight());
            }
        } 
    }
    
};

