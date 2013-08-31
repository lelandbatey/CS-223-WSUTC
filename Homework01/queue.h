
class queue
{
private:


    // Pointers to track the head and tail of the queue
    qNode* head;
    qNode* tail;


public:

    // Moved to public so that breadth first search can 
    typedef struct tQNode{// Defines the structure of the nodes to be used in the que for traversing the tree.
        struct tQNode *next_p; // Points to the "next" node in the queue for the tree.
        treeNode* tNode; // Pointer to a node on the binary search tree.
    } qNode;

    queue();
    ~queue();
    enqueue(treeNode*);
    dequeue();

    
};