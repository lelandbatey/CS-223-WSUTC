#include "kd_point.h"


class kd_node
{
private:
    
    
public:
    kd_node* left;
    kd_node* right;
    kd_point* value;

    kd_node(){
        left = right = 0;
        value = 0;
    };

    kd_node(kd_point* pnt){
        value = pnt;
    }
    // ~kd_node();

    
};