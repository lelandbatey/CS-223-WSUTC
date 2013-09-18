#include "node_template.h"


// using namespace std;


template <class T>
node_template<T>::node_template(){
    value = NULL;
    left = NULL;
    right = NULL;
}

template <class T>
void node_template<T>::setVal(T inVal){
    value = inVal;
}

template <class T>
T node_template<T>::getVal(){
    return value;    
}

template <class T>
node_template<T>* node_template<T>::getRight(){
    return &right;
}

template <class T>
node_template<T>* node_template<T>::getLeft(){
    return &left;
}

template <class T>
void node_template<T>::setRight(node_template* node){
    right = node;
}

template <class T>
void node_template<T>::setLeft(node_template* node){
    left = node;   
}