
// I'm dropping these typedefs here in the hope that this'll solve my scoping
// problems (how do I even C++!?)

typedef struct node{
    int value;
    int depth;
    struct node *leftChild;
    struct node *rightChild;
} treeNode;

typedef struct tQueueNode{// Defines the structure of the nodes to be used in the queue for traversing the tree.
    struct tQueueNode *next_p; // Points to the "next" node in the queue for the tree.
    treeNode* tNode; // Pointer to a node on the binary search tree.
} queueNode;



// So, something to note is that I'm going to be writing the queue, stack, and
// tree as part of the same class. Additionally, I'm going to be implementing
// the depth-first and breadth-first search as part of this same class as well.
// I realize by not making the stack and queue able to handle data in a generic
// way, I'm breaking one of the guidlines for this class that says our code must
// be reusable, but given the narrow use of this code, I've chosen to not do it
// that way.
using namespace std;

class tree
{

private:
    int maxDepth;
    map<int, int> widthMap;

    void recursePrint(treeNode* );
    void nodeAdd(int, treeNode**);
    void recurseDepth(treeNode* ,int);
    void findMaxDepth(treeNode* );
    void recurseWidth(treeNode* node);

    
    // Gotta have our root node!
    treeNode* root;
   

public:
    // typedef struct node{
    // int value;
    // struct node *leftChild;
    // struct node *rightChild;
    // } treeNode;

    tree();
    // ~tree();

    void depthFirstSearch();
    void breadthFirstSearch();

    void findMaxWidth();

    // We don't need the actual variable names in the .h file, just the types
    // that'll be used.
    void add(int);
    void print();
    void setDepth();

    


};
