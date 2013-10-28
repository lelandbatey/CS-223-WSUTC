// #include "stdlib.h"

#ifndef NULL
#define NULL 0
#endif

// So, after muddling around with not getting templates for a while, I did
// find a very helpfull page page here:
// http://stevenhickson.blogspot.com/2012/04/creating-basic-template-tree-class-in-c.html?m=1

// Though I did use it as a resource, I had already written most of this, I
// just needed some style/formatting guidance. And, I have the git commits to
// prove it!

// Also, I'm altering this a bit for use with my animals class.

template <class T>
class node_t
{
private:

    T value;
    node_t* left;
    node_t* right;
    node_t* parent;

public:

    node_t() {
        left = NULL;
        right = NULL;
        value = 0;
    };
    // ~node_t();

    void setVal(T &inVal ) {
        value = inVal;
    };

    T getVal() {
        return value;
    };

    // Declares getRight method returning reference to pointer of type "node_t"
    node_t*& getRight(){ 
        return right;
    };

    // Declares getLeft method returning reference to pointer of type "node_t"
    node_t*& getLeft() {
        return left;
    }; 
    
    node_t*& getParent() {
        return parent;
    }; 

    void setLeft(node_t* node) {
        left = node;
    };
    
    void setRight(node_t* node) {
        right = node;
    };

    void setParent(node_t* node) {
        parent = node;
    }
    // void print();

};


