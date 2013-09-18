#include "stdlib.h"

template <class T>
class node_template
{
    T value;
    node_template<T>* left;
    node_template<T>* right;
public:
    node_template();
    // ~node_template();

    void setVal(T);
    T getVal();
    node_template* getRight();

    node_template* getLeft();
    
    void setLeft(node_template*);
    
    void setRight(node_template*);
    void print();

};
