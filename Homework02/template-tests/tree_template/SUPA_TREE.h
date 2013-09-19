// SUPER TREE!
// Taken from here:
// http://stevenhickson.blogspot.com/2012/04/creating-basic-template-tree-class-in-c.html?m=1

#ifndef __TREE_CLASS__
#define __TREE_CLASS__

#ifndef NULL
#define NULL 0
#endif

//lets implement a basic templated tree
template <class T>
class Node {
public:
    T data;
    Node *left, *right, *parent;

    Node() {
        left = right = parent = NULL;
    };

    Node(T &value) {
        data = value;
    };

    ~Node() {
    };
    
    void operator= (const Node<T> &other) {
        data = other.data;
    };

    bool operator< (T &other) {
        return (data < other);
    };
};

//Our tree will contain the Node defined above
template <class T>
class Tree {
public:
    Tree() {
        root = NULL;
    };

    ~Tree() {
        m_destroy(root);
    };

    //We will define these all as virtuals for inherited trees (like a Huffman Tree and AVL Tree shown later)
    virtual void insert(T &value) {
        m_insert(root,NULL,value);
    };
    virtual Node<T>* search(T &value) {
        return m_search(root,value);
    };
    virtual bool remove(T &value) {
        return m_remove(root,value);
    };
    virtual bool operator< (Tree<T> &other) {
        return (root->data < other.first()->data);
    };
    void operator= (Tree<T> &other) {
        m_equal(root,other.first());
    };
    Node<T>*& first() {
        return root;
    };


protected:
    //this will be our root node and private functions
    Node<T> *root;
    void m_equal(Node<T>*& node, Node<T>* value) {
        if(value != NULL) {
            node = new Node<T>();
            *node = *value;
            if(value->left != NULL)
                m_equal(node->left, value->left);
            if(value->right != NULL)
                m_equal(node->right, value->right);
        }
    }

    void m_destroy(Node<T>* value) {
        if(value != NULL) {
            m_destroy(value->left);
            m_destroy(value->right);
            delete value;
        }
    };
    void m_insert(Node<T> *&node, Node<T> *parent, T &value) {
        if(node == NULL) {
            node = new Node<T>();
            *node = value;
            node->parent = parent;
        } else if(value < node->data) {
            m_insert(node->left,node,value);
        } else
            m_insert(node->right,node,value);
    };
    void m_insert(Node<T> *&node, Node<T> *parent, Tree<T> &tree) {
        Node<T> *value = tree.first();
        if(node == NULL) {
            node = new Node<T>();
            *node = *value;
            node->parent = parent;
        } else if(value->data < node->data) {
            m_insert(node->left,tree);
        } else
            m_insert(node->right,tree);
    };
    Node<T>* m_search(Node<T> *node, T &value) {
        if(node == NULL) 
            return NULL;
        else if(value == node->data)
            return node;
        else if(value < node->data)
            return m_search(node->left,value);
        else
            return m_search(node->right,value);
    };

    bool m_remove(Node<T> *node, T &value) {
        //messy, need to speed this up later
        Node<T> *tmp = m_search(root,value);
        if(tmp == NULL)
            return false;
        Node<T> *parent = tmp->parent;
        //am i the left or right of the parent?
        bool iamleft = false;
        if(parent->left == tmp)
            iamleft = true;
        if(tmp->left != NULL && tmp->right != NULL) {
            if(parent->left == NULL || parent->right == NULL) {
                parent->left = tmp->left;
                parent->right = tmp->right;
            } else {
                if(iamleft)
                    parent->left = tmp->left;
                else
                    parent->right = tmp->left;
                T data = tmp->right->data;
                delete tmp;
                m_insert(root,NULL,data);
            }
        } else if(tmp->left != NULL) {
            if(iamleft)
                parent->left = tmp->left;
            else
                parent->right = tmp->left;
        } else if(tmp->right != NULL ) {
            if(iamleft)
                parent->left = tmp->right;
            else
                parent->right = tmp->right;
        } else {
            if(iamleft)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        return true;
    };
};

template <class T>
class HuffmanTree : public Tree<T> {
public:
    //I have to put this again otherwise the 2nd insert function will overwrite the virtual void
    void insert(T &value) {
        m_insert(root,NULL,value);
    };
    void insert(HuffmanTree<T> &tree) {
        m_insert(root,NULL,tree);
    };
    void insert_left(Tree<T> &tree) {
        m_equal(root->left,tree.first());
    }
    void insert_right(Tree<T> &tree) {
        m_equal(root->right,tree.first());
    };
};

template <class T>
class AVLTree : public Tree<T> {
public:
    //I need to redefine the insert and remove functions so the tree balances
    void insert(T value) {
        m_insert(root,NULL,value);
        m_balance(root,NULL);
    };
    bool remove(T &value) {
        bool ret = m_remove(root,value);
        m_balance(root,NULL);
        return ret;
    };

private:
    void m_balance(Node<T> *&node, Node<T> *parent) {
        //there could be multiple cases since you can insert an entire tree
        //therefore we must check the balance of the entire tree

    }
};

#endif //__TREE_CLASS__