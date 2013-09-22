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


template <class T>
class node_t
{
    T value;
    node_t* left, right;
public:
    node_t() {
        left = NULL;
        right = NULL;
        value = NULL;
    };
    // ~node_t();

    void setVal(T &inVal ) {
        value = inVal;
    };

    T getVal() {
        return value;
    };

    node_t* getRi ght(){
        return right;
    };// Returns value of right ( which is an address that points to the "right" node)

    node_t* getLeft() {
        return left;
    }; // Returns value of left ( which is an address that points to the "left" node)
    
    void setLeft(node_t* node) {
        left = node;
    };
    
    void setRight(node_t* node) {
        right = node;
    };
    // void print();

};
