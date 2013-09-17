//Daniel Hanlen
#include "BinaryTree.h"
#include "TreeNode.h"

#include <vector>

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    if(root != NULL)
    {
        delete root;
    }
}

void BinaryTree::InsertValue(int value)
{
    if(root != NULL)
    {
        root->InsertValue(value);
    }
    else
    {
        root = new TreeNode(value);
    }
}

int BinaryTree::GetTreeHeight()
{
    if(root != NULL)
    {
        return root->GetTreeHeight();
    }
    // I was always taught that this kind of magic number is okay
    // Let me know and I won't use any numbers like this in future assignments
    return 0; // if no root node, the height is zero
}

// Creates two vectors and uses them to store the current level's nodes
// and the next level's nodes. It this goes until there are no more nodes
// in the tree, always storing the amount and first level where there are
// the most nodes
int BinaryTree::GetMaximumWidth(int & widthLevel)
{
    if(root == NULL)
    {
        // If no root node, the maxWidth is zero
        widthLevel = -1; // there is no level, so -1 is the proper,
                    // as 0 would suggest that data exists
        return 0; // no data, so zero width
    }

    //start at the beginning
    int maxWidth = 0;
    int currentLevel = 0;

    std::vector<TreeNode*> currentLevelRow; //current level opperating on
    std::vector<TreeNode*> nextLevelRow; // child nodes of all current levels

    // Initialize the first level
    currentLevelRow.push_back(root);

    while(currentLevelRow.size() > 0)
    {
        // set the maximum width if the new one is bigger
        if(maxWidth < currentLevelRow.size())
        {
            maxWidth = currentLevelRow.size();
            widthLevel = currentLevel;
        }

        //populate the next level
        while(currentLevelRow.size() > 0)
        {
            TreeNode * currentNode = currentLevelRow.back();
            currentLevelRow.pop_back();
            TreeNode * left  = currentNode->GetLeftChild();
            TreeNode * right = currentNode->GetRightChild();
            if(left != NULL)
            {
                nextLevelRow.push_back(left);
            }
            if(right != NULL)
            {
                nextLevelRow.push_back(right);
            }
        }

        //transfer the items between lists
        while(nextLevelRow.size() > 0)
        {
            currentLevelRow.push_back(nextLevelRow.back());
            nextLevelRow.pop_back();
        }
        currentLevel++;
    }
    return maxWidth;
}

