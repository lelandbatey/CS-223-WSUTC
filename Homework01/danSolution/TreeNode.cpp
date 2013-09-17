//Daniel Hanlen
#include "TreeNode.h"

//initialize children to NULL, and nodeValue to value
TreeNode::TreeNode(int value)
{
    nodeValue = value;
    leftChild = NULL;
    rightChild = NULL;
}

//when this node is deleted,
//make sure we delete the child nodes from memory as well
TreeNode::~TreeNode()
{
    if(leftChild != NULL)
    {
        delete leftChild;
    }
    if(rightChild != NULL)
    {
        delete rightChild;
    }
}

void TreeNode::InsertValue(int value)
{
    if(value < nodeValue)
    {
        if(leftChild != NULL)
        {
            leftChild->InsertValue(value);
        }
        else
        {
            leftChild = new TreeNode(value);
        }
    }
    else
    {
        if(rightChild != NULL)
        {
            rightChild->InsertValue(value);
        }
        else
        {
            rightChild = new TreeNode(value);
        }
    }
}

int TreeNode::GetTreeHeight()
{
    int currentHeight = 0;
    if(leftChild != NULL)
    {
        currentHeight = leftChild->GetTreeHeight();
    }
    if(rightChild != NULL)
    {
        int tempHeight = rightChild->GetTreeHeight();
        if(tempHeight > currentHeight)
        {
            currentHeight = tempHeight;
        }
    }
    return currentHeight + 1;
}

TreeNode * TreeNode::GetLeftChild()
{
    return leftChild;
}

TreeNode * TreeNode::GetRightChild()
{
    return rightChild;
}

