class tree
{
private:


    void nodeAdd(int, treeNode**);
    
    // Gotta have our root node!
    treeNode* root;

public:
    tree();
    ~tree();

    // We don't need the actual variable names in the .h file, just the types
    // that'll be used.
    void add(int);
    
    // This is moved to public so that the queue and the stack can easily build pointers of type node
    typedef struct node{
    int value;
    struct node *leftChild;
    struct node *rightChild;
    } treeNode;
};