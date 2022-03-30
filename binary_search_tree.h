#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstddef>
#include <iostream>

/*****************************************************
 **
 ** File:    binary_search.h
 ** Project: CSCE 221 Lab 4 Spring 2022
 ** Author:  Christian Mosquera
 ** Date:    03/21/22
 ** Section: 510
 ** Email:   cwbo.1701@tamu.edu
 ** 
 ** This file contains all the functions for the 
 ** binary search tree data structure. It has public 
 ** functions that a user can call and it utilizes
 ** internal private functions to help with recursion.
 **
 *****************************************************/


template <typename Comparable>
struct Node {
    Comparable value;
    Node* left;
    Node* right;
    Node() : value(), left(nullptr), right(nullptr) {}
    Node(Comparable value) : value(value), left(nullptr), right(nullptr) {}
};

template <typename Comparable>
class BinarySearchTree {

public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);
    bool contains(const Comparable& value) const;
    void insert(const Comparable& value);
    void remove(const Comparable& value);
    const Comparable& find_min() const;
    const Comparable& find_max() const;
    void print_tree(std::ostream& os=std::cout) const;
    bool is_empty() const;
    void make_empty();

private:
    // data
    Node<Comparable>* root;

    // recursive functions
    Node<Comparable>* recurse_find_max(Node<Comparable>* node) const;
    Node<Comparable>* recurse_find_min(Node<Comparable>* node) const;
    void insertRecurse(const Comparable& value, Node<Comparable>* &currNode);
    void preorderInsert(Node<Comparable>* current);
    void removeRecurse(const Comparable& value, Node<Comparable>* &current);
    void printRecurse(Node<Comparable>* node, int count, std::ostream& os=std::cout) const;
    bool containRecurse(Node<Comparable>* node, const Comparable& value) const;
    void emptyRecurse(Node<Comparable>* &node);

};


//---------------------------------------
// Name: Defalut Constructor
//---------------------------------------
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root(nullptr) {}



//---------------------------------------
// Name: Copy Constructor
// PreCondition:  other tree is given
// PostCondition: A deep copied second tree
//---------------------------------------
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& other) : root(nullptr) {

    // preorder traversal to copy
    if (other.root != nullptr) {
        this->preorderInsert(other.root);
    }

}



//---------------------------------------
// Name: Destructor
//---------------------------------------
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {

    make_empty();

}



//---------------------------------------
// Name: Copy assignment
// PreCondition:  other is given
// PostCondition: A deep copied tree
//---------------------------------------
template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& other) {

    // If this is the same as other
    if (this == &other) {
        return *this;
    }

    // make this empty first
    this->make_empty();

    // if other is empty
    if (other.root == nullptr) {
        this->root = nullptr;
        return *this;
    }

    // if other is non empty
    this->preorderInsert(other.root);
    return *this;
}



//---------------------------------------
// Name: contains
// PreCondition: Value is comparable
// PostCondition: Returns if value is in binary tree
//---------------------------------------
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& value) const {
    return containRecurse(root, value);
}



//---------------------------------------
// Name: containRecurse
// PreCondition:  Node is not nullptr and value is comparable
// PostCondition: Returns if value is in binary tree
//---------------------------------------
template <typename Comparable>
bool BinarySearchTree<Comparable>::containRecurse(Node<Comparable>* node, const Comparable& value) const {

    // nullptr base case
    if (node) {

        // found
        if (node->value == value) {
            return true;
        }

        // left sub tree
        else if (value < node->value) {
            return containRecurse(node->left, value);
        }

        // right sub tree
        else if (value > node->value) {
            return containRecurse(node->right, value);
        }
    }
    
    // goes through tree, not found
    return false;

}



//---------------------------------------
// Name: insert
// PreCondition:  Value is comparable
// PostCondition: Node inserted into the binary tree
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& value) {

    insertRecurse(value, this->root);

}



//---------------------------------------
// Name: insertRecurse
// PreCondition:  Value is comparable
// PostCondition: Node inserted into the binary tree
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::insertRecurse(const Comparable& value, Node<Comparable>* &currNode) {

    // base case
    if (currNode == nullptr) {
        currNode = new Node<Comparable>(value);
        return;
    }

    // left sub tree
    if (value < currNode->value) {
        insertRecurse(value, currNode->left);
    }

    // right sub tree
    else if (value > currNode->value) {
        insertRecurse(value, currNode->right);   
    }
    
}



//---------------------------------------
// Name: remove
// PreCondition:  Value is comparable
// PostCondition: Removes the value from the tree
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& value) {

    removeRecurse(value, this->root);

}



//---------------------------------------
// Name: removeRecurse
// PreCondition:  Value is comparable
// PostCondition: Removes the value from the tree
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::removeRecurse(const Comparable& value, Node<Comparable>* &current) {

    // nullptr base case
    if (!current) {
        return;
    }

    // found the value
    if (value == current->value) {

        // case 1: leaf node
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            current = nullptr;
        }

        // case 2: right sub tree and left sub tree
        else if (current->left && current->right) {

            // Find max in left sub tree
            Node<Comparable>* minRight = recurse_find_min(current->right);
            current->value = minRight->value;
            removeRecurse(minRight->value, current->right);

        }

        // case 3: right sub tree or left sub tree
        else if (current->right || current->left) {

            Node<Comparable>* temp = current;

            // right sub tree
            if (current->right) {
                current = current->right;
                delete temp;
            }

            // left sub tree
            else {
                current = current->left;
                delete temp;
            }
        }
    }

    else if (value < current->value) {
        removeRecurse(value, current->left);
    }

    else {
        removeRecurse(value, current->right);
    }
    
}



//---------------------------------------
// Name: find_min
// PreCondition:  Binary tree exists
// PostCondition: Returns the minimum value
//---------------------------------------
template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::find_min() const {

    Node<Comparable>* node = recurse_find_min(this->root);
    return node->value;

}



//---------------------------------------
// Name: recurse_find_min
// PreCondition:  Binary tree exists
// PostCondition: Returns the minimum value
//---------------------------------------
template <typename Comparable>
Node<Comparable>* BinarySearchTree<Comparable>::recurse_find_min(Node<Comparable>* node) const {

    // Throws error if the tree is empty
    if (!node) {
        throw std::invalid_argument("Tree is empty, no minimum value.");
    }

    // Traverse all the way to the left
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;

}



//---------------------------------------
// Name: find_max
// PreCondition:  Binary tree exists
// PostCondition: Returns maximum value
//---------------------------------------
template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::find_max() const {

    Node<Comparable>* node = recurse_find_max(this->root);
    return node->value;

}



//---------------------------------------
// Name: recurse_find_max
// PreCondition:  Binary tree exists
// PostCondition: Returns maximum value
//---------------------------------------
template <typename Comparable>
Node<Comparable>* BinarySearchTree<Comparable>::recurse_find_max(Node<Comparable>* node) const {

    // Throws error if the tree is empty
    if (!node) {
        throw std::invalid_argument("Tree is empty, no maximum value.");
    }

    // Traverse all the way to the right
    while (node->right != nullptr) {
        node = node->right;
    }

    return node;

}



//---------------------------------------
// Name: print_tree
// PreCondition:  Tree exists
// PostCondition: Outputs to the os stream that is specified
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::print_tree(std::ostream& os) const {
    if (this->root == nullptr) {
        os << "<empty>" << std::endl;
    }
    int count = -1;
    printRecurse(root, count, os);
}



//---------------------------------------
// Name: printRecurse
// PreCondition:  Tree exists
// PostCondition: Outputs to the os stream
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::printRecurse(Node<Comparable>* node, int count, std::ostream& os) const 
{
    // base case nullptr
    if (node) {

        // keeps count of the depth
        count++;

        printRecurse(node->right, count, os);

        // prints out the appropiate amount of spacing
        if (node != root) {
            for (int i = 0; i < count*2; i++) {
                os << " ";
            }
        }
        
        os << node->value << std::endl;
        printRecurse(node->left, count, os);
    }
}



//---------------------------------------
// Name: is_empty
// PreCondition:  N/A
// PostCondition: Returns true if root is nullptr
//---------------------------------------
template <typename Comparable>
bool BinarySearchTree<Comparable>::is_empty() const {

    return (root == nullptr);

}



//---------------------------------------
// Name: make_empty
// PreCondition:  Tree exists
// PostCondition: All nodes from tree are removed
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::make_empty() {

    emptyRecurse(root);

}



//---------------------------------------
// Name: emptyRecurse
// PreCondition:  Tree exists
// PostCondition: All nodes from tree are removed
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::emptyRecurse(Node<Comparable>* &node) {

    // base case for null
    if (node) {

        emptyRecurse(node->left);
        emptyRecurse(node->right);
        delete node;

    }

    node = nullptr;

}



//---------------------------------------
// Name: preorderInsert
// PreCondition:  Current is not nullptr
// PostCondition: A fully inserted binary search tree
//---------------------------------------
template <typename Comparable>
void BinarySearchTree<Comparable>::preorderInsert(Node<Comparable>* current) {

    // base case if null
    if (current) {
        this->insert(current->value);
        this->preorderInsert(current->left);
        this->preorderInsert(current->right);
    }

    return;

}


#endif