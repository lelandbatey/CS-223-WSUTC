//Daniel Hanlen
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "TreeNode.h"

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void InsertValue(int);

    int GetTreeHeight();
    int GetMaximumWidth(int &);
private:
    //the root node
    TreeNode *root;
};

#endif
