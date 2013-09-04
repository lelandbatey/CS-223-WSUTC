// #include "stack.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map> // Dictionary/map
#include "tree.h"
#include "queue.h"

using namespace std;

// Ok, so in the .cpp file, we implement only the methods, and we use the format:
//
// return_type class_name::method_name( parameters ){...}

tree::tree(){
    root = 0;
    maxDepth = 1;
}


void tree::add(int i){
    // cout << root << endl;
    // cout << root->rightChild << endl;
    // cout << root->leftChild <<endl; 
    // cout << root->value << endl;
    nodeAdd(i, &root);
}


// NOTE:

// While I am trying to be as original as possible about his entire assignment,
// I used this web-page for reference: http://www.thegeekstuff.com/2013/02/c
// -binary-tree/ I feel like my code ended up looking a lot like the code on
// that page, but I don't really know what I could have done to prevent that
// (given it's simplicity), so I've tried to make sure I understand and
// subsequently can explain what's going on.
void tree::nodeAdd(int leefVal, treeNode** node){

    // Here we set up a superpointer so that we can actually point it at more pointers.
    
    treeNode *holderNode = NULL; // Will be used for the insertion

    // If there's not a node where there needs to be, then allocate the memory,
    // and assign our data appropriately to a temporary node, then swap it in.
    // cout << "We're now gonna check if the node's null." << endl;
    if ( *node == 0 ){
        // cout << "The node's null." << endl;
        
        holderNode = (treeNode*)malloc(sizeof(treeNode));
        holderNode->leftChild  = NULL;
        holderNode->rightChild = NULL;
        holderNode->value      = leefVal;

        *node = holderNode;
        return;
    } 
    // cout << "we've checked if the node's null." << endl;
    // cout << "Is it bigger?" << endl;
    if ( leefVal > (*node)->value ){ // If it's bigger than our node, check out what's happening on the right node
        // cout << "\trightChild" << endl;
        nodeAdd(leefVal, &(*node)->rightChild);
    }

    // cout<< "Is it smaller?" << endl;
    if (leefVal < (*node)->value){ // Otherwise, check out the left node
        // cout << "\tleftChild" << endl;
        nodeAdd(leefVal, &(*node)->leftChild);
    }

    if (leefVal == (*node)->value){ // Oh noes, it's equal :( Now we gotta do some black magic...
        // cout << "\tthey're totally equal" << endl;
        // So we allocate the appropriate placeholder node
        holderNode = (treeNode*)malloc(sizeof(treeNode));
        holderNode->leftChild  = NULL;
        holderNode->rightChild = (*node)->rightChild; // Here we set the it so that the right-side child of the temporary node points to the same node that is currently being pointed to by the main tree node. It might look like this:
          //
          //   root   placeholder                 
          //   / \   /                  
          //  /   \ /                   
          // y     z                    
                                      
        holderNode->value = leefVal;


        (*node)->rightChild = holderNode; // Here, we implicitly sever the connection between the original two nodes, and connect our placeholder node as the man in the middle.
    }
    return;
}

void tree::print(){
    recursePrint(root);
}

void tree::recursePrint(treeNode* node){
    if (node->leftChild){
        recursePrint(node->leftChild);
    }
    // cout << node->value << endl;
    // cout << node->depth << endl;// Awwwww yeah, cout.
    if (node->rightChild){
        recursePrint(node->rightChild);
    }
}

void tree::depthFirstSearch(){
    return;
}

// This is largely derived from here: http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/#comment-1016408312
void tree::breadthFirstSearch(){
    
    cout << "New queue created" << endl;

    queue myQueue;
    int width = 1;
    int max_width = 0;

    treeNode* node;
    treeNode* markerNode;

    node = root;
    markerNode = node;

    if (!this->root){
        return;
    }

    // cout << "qCount: " << myQueue.count() << endl;

    myQueue.enqueue(root);

    // cout << "\t We did enqueue it!" << endl;

    if (myQueue.empty())
    {
        cout << "The queue's empty!!" << endl;
    }

    while (!myQueue.empty()){
        cout << "Attempting to dequeue" << endl;
        node = myQueue.dequeue();
        cout << node->value << endl;
        cout << "Dqed correctly" << endl;

        myQueue.enqueue(node->leftChild);
        myQueue.enqueue(node->rightChild);

        if (markerNode == node || myQueue.empty() ){
            markerNode = node->leftChild;

            if (max_width < width){
                max_width = width;
            }
            width = 0;
        }
        width++;
        cout << node->value << endl;
        cout << node->rightChild->value <<endl;
        cout << max_width << endl;
        // cout << "qCount: " << myQueue.count() << endl;

        myQueue.walk();
    }

    cout << "The maximum width is: " << max_width << endl;
    return;
}

void tree::recurseDepth(treeNode* node, int level){
    // cout << level << endl;
    node->depth = level;
    if (node->leftChild)
    {
        recurseDepth(node->leftChild, level+1);
    }
    if (node->rightChild)
    {
        recurseDepth(node->rightChild, level+1);
    }
}

void tree::findMaxDepth(treeNode* node){
    if (node->depth >= maxDepth){
        // cout << "New Max depth!" << node->depth << endl;
        maxDepth = node->depth;
    } else {
        // cout << node->depth << "is not bigger than " << maxDepth << endl;
    }


    if (node->leftChild){
        findMaxDepth(node->leftChild);
    }
    if (node->rightChild){
        findMaxDepth(node->rightChild);
    }
}

void tree::setDepth(){
    recurseDepth(root,1);
    findMaxDepth(root);
    cout << "Tree Height: " << maxDepth << endl; 
}

void tree::findMaxWidth(){
    int i;
    int largest = 1;
    int largeLevel = 1;
    recurseWidth(root);
    for (i = 0; i < (maxDepth*maxDepth); ++i)
    {
        // cout << "Widthmap at index " << i<< " :"<< widthMap[i] << endl;
        if (widthMap[i] > largest)
        {
            largest = widthMap[i];
            largeLevel = i;
        }
    }
    cout << "Maximum Width: " << largest << endl;
    cout << "Maximum Width Level: " << largeLevel << endl;
}

void tree::recurseWidth(treeNode* node){
    // cout << widthMap[node->depth] << endl;
    if (widthMap[node->depth])
    {
        widthMap[node->depth]++;
    } else {
        widthMap[node->depth] = 1;
    }

    if (node->leftChild){
        recurseWidth(node->leftChild);
    }
    if (node->rightChild){
        recurseWidth(node->rightChild);
    }

}