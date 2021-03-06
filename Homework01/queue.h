
class queue
{
private:


    // Pointers to track the head and tail of the queue
    queueNode* head;
    queueNode* tail;
    int qCount;


public:

    // // Moved to public so that breadth first search can 
    // typedef struct tQueueNode{// Defines the structure of the nodes to be used in the queue for traversing the tree.
    //     struct tQueueNode *next_p; // Points to the "next" node in the queue for the tree.
    //     tree.treeNode* tNode; // Pointer to a node on the binary search tree.
    // } queueNode;

    queue();
    int count();
    // ~queue();
    void enqueue(treeNode*);
    treeNode* dequeue();
    int empty();
    void first();
        
    void walk();
};

