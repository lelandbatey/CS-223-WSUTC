//Daniel Hanlen
#ifndef NULL
#define NULL 0
#endif

#ifndef _TREENODE_H
#define _TREENODE_H
class TreeNode
{
public:
    TreeNode(int value);
    ~TreeNode();

    void InsertValue(int);

    int GetTreeHeight();

    //for use in getting the maximum width
    TreeNode * GetLeftChild();
    TreeNode * GetRightChild();
private:
    TreeNode * leftChild;
    TreeNode * rightChild;

    int nodeValue;
};

#endif
