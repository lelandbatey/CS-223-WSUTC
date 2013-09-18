// #include "node_template.cpp"

template <class T>
class tree_template
{
    node_template<T>* root;
    void addNode(T, node_template<T>*); // Internal recursive add function
public:
    tree_template();
    // ~tree_template();

    /* data */
    void add(T);
    void print();
};