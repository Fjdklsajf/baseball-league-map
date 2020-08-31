/******************************************************************************
 *  AUTHOR       : Zhongming Su
 *  ASSIGNMENT #6: Binary Search Trees
 *  CLASS        : CS 008
 *  DUE DATE     : 4/20/2020
 ******************************************************************************/
#ifndef TREE_H_
#define TREE_H_

#include <iostream>


template <class value_type>
struct Node {
    //Constructor: Initailize a node
    Node(const value_type& val, Node<value_type>* left = nullptr, 
            Node<value_type>* right = nullptr) {
        value = val;
        _left = left;
        _right = right;
    }
    value_type value;
    Node<value_type>* _left;
    Node<value_type>* _right;
};

template <class value_type>
class Tree {
  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    Tree();
    Tree(const Tree<value_type>& t);
    ~Tree();

    /***************
     ** ACCESSORS **
     ***************/
    int size() const;
    Node<value_type>* getRoot() const;

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
     ***********************************/
    void insert(const value_type& value);
    bool remove(const value_type& value);
    bool remove(const value_type& value, Node<value_type>*& parent);
    void replaceRoot(Node<value_type>*& parent);
    void destroySubTree(Node<value_type>* parent);
    Tree<value_type>& operator =(const Tree<value_type>& t);
    void copy(Node<value_type>*& target, Node<value_type>* t);

    /*******************************
     ** CONSTANT MEMBER FUNCTIONS **
     *******************************/
    Node<value_type>* searchNode(const value_type& value) const;
    bool empty() const;
    bool find(const value_type& value) const;
    void getPrint(std::ostream& out);
    void getPrint(std::ostream& out, Node<value_type>* parent);

  private:
    Node<value_type>* _root;
    int _size;
};
/******************************************************************************
 *  Tree Class
 *    Includes the functionalities of a binary search tree
 ******************************************************************************/


/******************************************************************************
 *
 *  Default Constructor Tree
 *_____________________________________________________________________________
 *  Creates an empty tree
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _size set to 0, _root point to null
 ******************************************************************************/
template <class value_type>
Tree<value_type>::Tree() {
    _root = nullptr;
    _size = 0;
}

/******************************************************************************
 *
 *  Copy Constructor Tree
 *_____________________________________________________________________________
 *  Copy elements from another tree over
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    all nodes are copied
 ******************************************************************************/
template <class value_type>
Tree<value_type>::Tree(const Tree<value_type>& t) {
    _size = 0;
    copy(_root, t.getRoot());
}

/******************************************************************************
 *
 *  Destructor Tree
 *_____________________________________________________________________________
 *  Destroy the binary search tree
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    each node is deleted
 ******************************************************************************/
template <class value_type>
Tree<value_type>::~Tree() {
    destroySubTree(_root);
}

/******************************************************************************
 *
 *  Accessor size: Class Tree
 *_____________________________________________________________________________
 *  Get the number of nodes in the tree
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return _size
 ******************************************************************************/
template <class value_type>
int Tree<value_type>::size() const {
    return _size;
}

/******************************************************************************
 *
 *  Accessor getRoot: Class Tree
 *_____________________________________________________________________________
 *  Get the _root node of the tree
 *  - returns Node<value_type>*
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return _root
 ******************************************************************************/
template <class value_type>
Node<value_type>* Tree<value_type>::getRoot() const {
    return _root;
}

/******************************************************************************
 *
 *  Method insert: Class Tree
 *_____________________________________________________________________________
 *  Insert the new value into the tree in a sorted manner, if it is not
 *      already found in the tree
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    value is added if not already exist
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::insert(const value_type& value) {
    if(_root == nullptr) {                       //empty tree case
        _root = new Node<value_type>(value);
        _size++;
        return;
    }

    Node<value_type>* pos = _root;
    Node<value_type>* insert = new Node<value_type>(value);

    while(pos != nullptr) {
        if(pos->value == value) {               //existed value_type
            return;
        }
        if(value > pos->value) {
            if(pos->_right == nullptr) {    //right path
                pos->_right = insert;
                _size++;
                return;
            }
            pos = pos->_right;
        } else {
            if(pos->_left == nullptr) {     //left path
                pos->_left = insert;
                _size++;
                return;
            }
            pos = pos->_left;
        }
    }
}

/******************************************************************************
 *
 *  Method remove: Class Tree
 *_____________________________________________________________________________
 *  Remove the value given from the tree
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    searchNode(value) != nullptr
 *
 *  POST-CONDITIONS
 *    value is removed from the tree
 ******************************************************************************/
template <class value_type>
bool Tree<value_type>::remove(const value_type& value) {
    if(searchNode(value) == nullptr) {
        return false;
    }
    _size--;
    return remove(value, _root);
}

/******************************************************************************
 *
 *  Method remove: Class Tree
 *_____________________________________________________________________________
 *  Remove the given value from the given sub-tree
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    searchNode(value) != nullptr
 *
 *  POST-CONDITIONS
 *    value is removed from the tree
 ******************************************************************************/
template <class value_type>
bool Tree<value_type>::remove(const value_type& value, Node<value_type>*& parent) {
    if(value == parent->value) {
        replaceRoot(parent);
    } else if (value > parent->value) {
        remove(value, parent->_right);
    } else {
        remove(value, parent->_left);
    }
    return true;
}

/******************************************************************************
 *
 *  Method replaceRoot: Class Tree
 *_____________________________________________________________________________
 *  Root of a sub-tree is replaced by the successor
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    parent is replaced
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::replaceRoot(Node<value_type>*& parent) {
    Node<value_type>* temp;
    //Leaf
    if(parent->_left == nullptr && parent->_right == nullptr) {
        _root = nullptr;
        delete parent;
    } else if(parent->_left == nullptr) {   //only right
        temp = parent;
        parent = parent->_right;
        delete temp;
    } else if(parent->_right == nullptr) {  //only left
        temp = parent;
        parent = parent->_left;
        delete temp;
    } else {                                    //both children
        temp = parent->_right;
        if(temp->_left == nullptr) {
            temp->_left = parent->_left;
            delete parent;
            parent = temp;
        } else {
            while(temp->_left->_left != nullptr) {
                temp = temp->_left;
            }
            Node<value_type>* successor = temp->_left;
            temp->_left = successor->_right;
            successor->_left = parent->_left;
            successor->_right = parent->_right;
            delete parent;
            parent = successor;
        }
    }
}

/******************************************************************************
 *
 *  Method destroySubTree: Class Tree
 *_____________________________________________________________________________
 *  An entire sub-tree is destroyed
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    every node linked from parent is deleted
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::destroySubTree(Node<value_type>* parent) {
    if(parent == nullptr) {
        return;
    }
    if(parent->_left) {
        destroySubTree(parent->_left);
    }
    if(parent->_right) {
        destroySubTree(parent->_right);
    }
    delete parent;
}

/******************************************************************************
 *
 *  Overload operator =: Class Tree
 *_____________________________________________________________________________
 *  Copies all nodes from another tree
 *  - returns Tree<value_type>&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    this != &t
 *
 *  POST-CONDITIONS
 *    current tre e is replaced by nodes of given tree
 ******************************************************************************/
template <class value_type>
Tree<value_type>& Tree<value_type>::operator =(const Tree<value_type>& t) {
    if(this == &t) {
        return *this;
    }
    destroySubTree(_root);
    copy(_root, t.getRoot());
    return *this;
}

/******************************************************************************
 *
 *  Method copy: Class Tree
 *_____________________________________________________________________________
 *  Copies content of one node to another, and all its children
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    target becomes a copy of t, along with its children
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::copy(Node<value_type>*& target, Node<value_type>* t) {
    if(t == nullptr) {
        return;
    } 
    _size++;
    target = new Node<value_type>(t->value);
    copy(target->_left, t->_left);
    copy(target->_right, t->_right);
}

/******************************************************************************
 *
 *  Method searchNode: Class Tree
 *_____________________________________________________________________________
 *  Check if value exists in the tree
 *  - returns Node<value_type>*
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return the node if value if found, null otherwise
 ******************************************************************************/
template <class value_type>
Node<value_type>* Tree<value_type>::searchNode(const value_type& value) const {
    Node<value_type>* pos = _root;
    while(pos != nullptr) {
        if(value > pos->value) {
            pos = pos->_right;
        } else if (value < pos->value) {
            pos = pos->_left;
        } else {
            return pos;
        }
    }
    return nullptr;
}

/******************************************************************************
 *
 *  Method empty: Class Tree
 *_____________________________________________________________________________
 *  Find the emptiness of the tree
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true is _size is 0
 ******************************************************************************/
template <class value_type>
bool Tree<value_type>::empty() const {
    return _size <= 0;
}

/******************************************************************************
 *
 *  Method find: Class Tree
 *_____________________________________________________________________________
 *  Find if the value exist in the tree
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if value is found
 ******************************************************************************/
template <class value_type>
bool Tree<value_type>::find(const value_type& value) const {
    return searchNode(value) != nullptr;
}

/******************************************************************************
 *
 *  Method getPrint: Class Tree
 *_____________________________________________________________________________
 *  Write values in the tree to ostream in ascending order, starting at root
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    output is written to ostream
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::getPrint(std::ostream& out) {
    getPrint(out, _root);
}

/******************************************************************************
 *
 *  Method getPrint: Class Tree
 *_____________________________________________________________________________
 *  Write values in the tree to ostream in ascending order, starting at given parent
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    output is wrtiten to ostream
 ******************************************************************************/
template <class value_type>
void Tree<value_type>::getPrint(std::ostream& out, Node<value_type>* parent) {
    if(parent) {
        getPrint(out, parent->_left);
        out << parent->value << std::endl;
        getPrint(out, parent->_right);
    }
}

#endif // TREE_H_
