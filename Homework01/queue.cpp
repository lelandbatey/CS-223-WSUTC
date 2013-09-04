#include "tree.h"
#include "queue.h"
#include <stdlib.h> // Gotta have out NULLs

void queue::enqueue(treeNode* leafNode){// I'm running out of "node" synonyms,
                                        //I'll just have to deal with the vague-
                                        //ness of the name "leafNode"

    queueNode* tempNode = NULL; // Dis gon be new node for the stack.

    // Set aside memory, zero out initial values.
    tempNode = (queueNode*)malloc(sizeof(queueNode));
    tempNode->next_p = NULL;

    tempNode->tNode = leafNode;

    // Points the "next" pointer of the last node to the new node, then sets the
    // "tail" of the queue to reference the new node.
    this->tail->next_p = tempNode;
    tail = tempNode;

    return;
}

treeNode* queue::dequeue(){
    
    treeNode* toReturn;// Will be the thing we return (duh)

    if (head)
    {   
    // Set's up toReturn to point to the treeNode that was being referenced by
    // the head, then points our head to the next item in the queue.
        toReturn = head->tNode;

        if (head->next_p){ // If there's another node in the queue, set the head to that.
            head = head->next_p;
        } else { // If there's NOT another node in the queue, set head to NULL
            head = NULL;
        }

    } else {// Oops, the queue's empty, nothing to return :/
        toReturn = NULL;
    }

    return toReturn;

}

// Returns true if the queue is empty (no nodes in the queue/head is NULL)
int queue::empty(){

    if (head){
        return 0;
    } else {
        return 1;
    }

}
