
// So, something to note is that I'm going to be writing the queue, stack, and
// tree as part of the same class. Additionally, I'm going to be implementing
// the depth-first and breadth-first search as part of this same class as well.
// I realize by not making the stack and queue able to handle data in a generic
// way, I'm breaking one of the guidlines for this class that says our code must
// be reusable, but given the narrow use of this code, I've chosen to not do it
// that way.
class tree
{

public:
    typedef struct node{
    int value;
    struct node *leftChild;
    struct node *rightChild;
    } treeNode;

    tree();
    ~tree();

    void depthFirstSearch();
    void breadthFirstSearch();

    // We don't need the actual variable names in the .h file, just the types
    // that'll be used.
    void add(int);

    
private:


    void nodeAdd(int, treeNode**);
    
    // Gotta have our root node!
    treeNode* root;

   

};