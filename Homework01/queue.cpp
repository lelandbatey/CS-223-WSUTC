#include <stdlib.h> // Gotta have out NULLs
#include <iostream>
#include <map> // Dictionary/map
#include "tree.h"
#include "queue.h"

using namespace std;

void queue::enqueue(treeNode* leafNode){// I'm running out of "node" synonyms,
                                        //I'll just have to deal with the vague-
                                        //ness of the name "leafNode"

    cout << "  ===" << leafNode->value << "===\n";
    queueNode* tempNode = NULL; // Dis gon be new node for the stack.

    // cout << "About to set aside memory." << endl;
    // Set aside memory, zero out initial values.
    tempNode = (queueNode*)malloc(sizeof(queueNode));
    tempNode->next_p = NULL;

    // cout << "Setting queueNode to point to leaf." << endl;
    // cout << leafNode << endl;
    tempNode->tNode = leafNode;

    // cout << "Set's the tail to point to our new node." << endl;

    if (tail){   
        // Points the "next" pointer of the last node to the new node, then sets the
        // "tail" of the queue to reference the new node.
        cout << "   there's a tail\n";
        this->tail->next_p = tempNode;
        if (head)
        {
            cout << "   there's a head.\n";
        } else {
            head = tail;
            cout << "   NO HEAD\n";
        }
    } else {
        head = tempNode;
        tail = tempNode;
    }

    // cout << "Tail appropriately set" << endl;
    tail = tempNode;

    qCount++;

    return;
}

treeNode* queue::dequeue(){
    
    if (qCount){
        qCount--;
    }

    cout << "\tGot past the qCount\n";

    treeNode* toReturn;// Will be the thing we return (duh)

    cout << "\tAttempting to make the check.\n";
    if (head)
    {   
    // Set's up toReturn to point to the treeNode that was being referenced by
    // the head, then points our head to the next item in the queue.
        cout << "\tThere's a head" << endl;
        toReturn = head->tNode;

        if (head->next_p){ // If there's another node in the queue, set the head to that.
            cout << "\t And there's a next object" << endl;
            head = head->next_p;
            cout << "\t  Next head assign worked" << endl;
        } else { // If there's NOT another node in the queue, set head to NULL
            cout << "\tBut there's no next object." << endl;
            head = NULL;
        }

    } else {// Oops, the queue's empty, nothing to return :/
        cout << "\tTHere's no head to dequeue!\n";
        toReturn = NULL;
    }

    

    return toReturn;

}

// Returns true if the queue is empty (no nodes in the queue/head is NULL)
int queue::empty(){

    if (qCount){
        return 0;
    } else {
        return 1;
    }

}

int queue::count(){
    return qCount;
}

queue::queue(){
    head = NULL;
    tail = NULL;
    qCount = 0;
}

void queue::walk(){
    queueNode* node;
    node = head;
    for (;;){
        if (node){
            cout << node << endl;
            // cout << node->value << endl;
            node = node->next_p;
        }else{
            break;
        }
    }
}