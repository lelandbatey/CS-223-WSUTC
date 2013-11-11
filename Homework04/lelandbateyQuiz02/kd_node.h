#include "kd_point.h"


class kd_node
{
private:


public:
    kd_node* left;
    kd_node* right;
    kd_point* value;
    int k_dim;

    kd_node(){
        left = right = NULL;
        value = 0;
        k_dim = 0;
    };

    kd_node(kd_point* pnt){
        value = pnt;
        left = 0;
        right = 0;
        k_dim = 0;
    }

    kd_node(kd_point* pnt, int k){
        value = pnt;
        left = 0;
        right = 0;
        k_dim = k;
    }

    kd_point*& getVal(){
        return value;
    }
    kd_node*& getRight(){
        return right;
    }
    kd_node*& getLeft(){
        return left;
    }
    int getK(){
        return k_dim;
    }
    void setVal(kd_point*& point){
        value = point;
    }
    void setRight(kd_node*& node){
        right = node;
    }
    void setLeft(kd_node*& node){
        left = node;
    }

    // ~kd_node();

    
};