#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstddef>
#include <iostream>


/*****************************************************
 **
 ** File:    avl_tree.h
 ** Project: CSCE 221 Lab 4 Spring 2022
 ** Author:  Christian Mosquera
 ** Date:    03/21/22
 ** Section: 510
 ** Email:   cwbo.1701@tamu.edu
 ** 
 ** This file contains all the functions for avl tree
 ** and their implementaions. There are public functions
 ** that the user can call and their are private functions
 ** that help the public functions perform their actions.
 **
 *****************************************************/

template <typename Comparable>
class AVLTree {

public:

    AVLTree();
    AVLTree(const AVLTree& other);
    ~AVLTree();
    AVLTree& operator=(const AVLTree& other);
    bool contains(const Comparable& value) const;
    void insert(const Comparable& value);
    void remove(const Comparable& value);
    const Comparable& find_min() const;
    const Comparable& find_max() const;
    void print_tree(std::ostream& os=std::cout) const;
    bool is_empty() const;
    void make_empty();

private:

    struct AVLNode {
        int height;
        AVLNode* left;
        AVLNode* right;
        Comparable value;
        AVLNode() : height(0), left(nullptr), right(nullptr), value() {}
        AVLNode(Comparable value) : height(0), left(nullptr), right(nullptr), value(value) {}
    };

    AVLNode* root;

    void preorderInsert(AVLNode* current);
    void insertRecurse(const Comparable& value, AVLNode* &currNode);
    void singleLeftShift(AVLNode* &node);
    int findHeight(AVLNode* node) const;
    int max(int a, int b);
    void balance(AVLNode* &node);
    void singleRightShift(AVLNode* &node);
    void removeRecurse(const Comparable& value, AVLNode* &current);
    Comparable& recurse_find_min(AVLNode* node) const;
    Comparable& recurse_find_max(AVLNode* node) const;
    void printRecurse(AVLNode* node, int count, std::ostream& os) const;
    void emptyRecurse(AVLNode* &node);
    bool containRecurse(AVLNode* node, const Comparable& value) const;

    
};



//---------------------------------------
// Name: Defalut Constructor
//---------------------------------------
template <typename Comparable>
AVLTree<Comparable>::AVLTree() : root(nullptr) {}



//---------------------------------------
// Name: Copy Constructor
// PreCondition:  other tree is given
// PostCondition: A deep copied second tree
//---------------------------------------
template <typename Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree& other) : root(nullptr) {

    // preorder traversal to copy
    if (other.root != nullptr) {
        this->preorderInsert(other.root);
    }

}



//---------------------------------------
// Name: Destructor
//---------------------------------------
template <typename Comparable>
AVLTree<Comparable>::~AVLTree() {

    make_empty();
    
}



//---------------------------------------
// Name: Copy assignment
// PreCondition:  other is given
// PostCondition: A deep copied tree
//---------------------------------------
template <typename Comparable>
AVLTree<Comparable>& AVLTree<Comparable>::operator=(const AVLTree& other) {

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
bool AVLTree<Comparable>::contains(const Comparable& value) const {

    return containRecurse(root, value);

}



//---------------------------------------
// Name: containRecurse
// PreCondition:  Node is not nullptr and value is comparable
// PostCondition: Returns if value is in binary tree
//---------------------------------------
template <typename Comparable>
bool AVLTree<Comparable>::containRecurse(AVLNode* node, const Comparable& value) const {

    // Base case for nullptr
    if (node) {

        // Found value
        if (node->value == value) {
            return true;
        }

        // Traverse left
        else if (value < node->value) {
            return containRecurse(node->left, value);
        }
        
        // Traverse right
        else if (value > node->value) {
            return containRecurse(node->right, value);
        }

    }
    
    // Once it traverses to a null
    return false;

}



//---------------------------------------
// Name: insert
// PreCondition:  Value is comparable
// PostCondition: Node inserted into the binary tree
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable& value) {

    insertRecurse(value, root);

}



//---------------------------------------
// Name: insertRecurse
// PreCondition:  Value is comparable
// PostCondition: Node inserted into the binary tree
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::insertRecurse(const Comparable& value, AVLNode* &currNode) {

    // base case
    if (currNode == nullptr) {
        currNode = new AVLNode(value);
    }

    // left sub tree
    else if (value < currNode->value) {
        insertRecurse(value, currNode->left);
    }

    // right sub tree
    else if (value > currNode->value) {
        insertRecurse(value, currNode->right);   
    }

    // Balance the tree
    balance(currNode);

}



//---------------------------------------
// Name: remove
// PreCondition:  Value is comparable
// PostCondition: Removes the value from the tree
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable& value) {

    removeRecurse(value, this->root);

}



//---------------------------------------
// Name: removeRecurse
// PreCondition:  Value is comparable
// PostCondition: Removes the value from the tree
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::removeRecurse(const Comparable& value, AVLNode* &current) {

    // find value
    if (!current) {
        return;
    }

    if (value == current->value) {

        // case 1: leaf node
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            current = nullptr;
        }

        // case 2: right sub tree and left sub tree
        else if (current->left && current->right) {

            // Find max in left sub tree
            Comparable& minRight = recurse_find_min(current->right);
            current->value = minRight;
            removeRecurse(minRight, current->right);

        }

        // case 3: right sub tree or left sub tree
        else if (current->right || current->left) {

            AVLNode* temp = current;
            if (current->right) {
                current = current->right;
                delete temp;
            }
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
    
    // At the end of inserting, make sure tree balanced
    balance(current);
    
}



//---------------------------------------
// Name: find_min
// PreCondition:  Binary tree exists
// PostCondition: Returns the minimum value
//---------------------------------------
template <typename Comparable>
const Comparable& AVLTree<Comparable>::find_min() const {

    return recurse_find_min(root);

}



//---------------------------------------
// Name: recurse_find_min
// PreCondition:  Binary tree exists
// PostCondition: Returns the minimum value
//---------------------------------------
template <typename Comparable>
Comparable& AVLTree<Comparable>::recurse_find_min(AVLNode* node) const{

    // Throws error if the tree is empty
    if (!node) {
        throw std::invalid_argument("Tree is empty, no minimum value.");
    }

    // Traverse all the way to the left
    if (node->left == nullptr) {
        return node->value;
    }
    return recurse_find_min(node->left);

}



//---------------------------------------
// Name: find_max
// PreCondition:  Binary tree exists
// PostCondition: Returns maximum value
//---------------------------------------
template <typename Comparable>
const Comparable& AVLTree<Comparable>::find_max() const {
    
    return recurse_find_max(this->root);

}



//---------------------------------------
// Name: recurse_find_max
// PreCondition:  Binary tree exists
// PostCondition: Returns maximum value
//---------------------------------------
template <typename Comparable>
Comparable& AVLTree<Comparable>::recurse_find_max(AVLNode* node) const {

    // Throws error if the tree is empty
    if (!node) {
        throw std::invalid_argument("Tree is empty, no maximum value.");
    }

    // Traverse all the way to the right
    if (node->right == nullptr) {
        return node->value;
    }

    return recurse_find_max(node->right);

}



//---------------------------------------
// Name: print_tree
// PreCondition:  Tree exists
// PostCondition: Outputs to the os stream that is specified
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::print_tree(std::ostream& os) const {

    // If tree is empty
    if (this->root == nullptr) {
        os << "<empty>" << std::endl;
    }

    // non empty tree
    int count = -1;
    printRecurse(root, count, os);
}



//---------------------------------------
// Name: printRecurse
// PreCondition:  Tree exists
// PostCondition: Outputs to the os stream
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::printRecurse(AVLNode* node, int count, std::ostream& os) const {

    // check for nullptr
    if (node) {

        // Keep track of depth
        count++;

        printRecurse(node->right, count, os);

        // Determine amount of spacing
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
bool AVLTree<Comparable>::is_empty() const {

    return (root == nullptr);

}



//---------------------------------------
// Name: make_empty
// PreCondition:  Tree exists
// PostCondition: All nodes from tree are removed
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::make_empty() {

    emptyRecurse(root);

}

//---------------------------------------
// Name: emptyRecurse
// PreCondition:  Tree exists
// PostCondition: All nodes from tree are removed
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::emptyRecurse(AVLNode* &node) {

    // Base case for nullptr
    if (node) {
        
        emptyRecurse(node->left);
        emptyRecurse(node->right);
        delete node;

    }

    // make node nullptr
    node = nullptr;
}



//---------------------------------------
// Name: findHeight
// PreCondition:  node is given
// PostCondition: Returns the height of the node
//---------------------------------------
template <typename Comparable>
int AVLTree<Comparable>::findHeight(AVLNode* node) const{
    
    // null nodes are height -1, otherwise return stored height
    return !node? -1 : node->height;

}



//---------------------------------------
// Name: max
// PreCondition:  a and b are given
// PostCondition: Returns the greater of the two
//---------------------------------------
template <typename Comparable>
int AVLTree<Comparable>::max(int a, int b) {

    // returns max value
    return a > b ? a : b;

}



//---------------------------------------
// Name: preorderInsert
// PreCondition:  Current is not nullptr
// PostCondition: A fully inserted binary search tree
//---------------------------------------
template <typename Comparable>
void AVLTree<Comparable>::preorderInsert(AVLNode* current) {

    // base case if null
    if (current) {
        this->insert(current->value);
        this->preorderInsert(current->left);
        this->preorderInsert(current->right);
    }

    return;

}



template <typename Comparable>
void AVLTree<Comparable>::balance(AVLNode* &node) {
    
    if (!node) {
        return;
    }
    
    // Balance factor
    int factor = findHeight(node->left) - findHeight(node->right);

    // Right skewed
    if (factor < -1) {

        // Single shift left right skewed
        if (findHeight(node->right->right) >= findHeight(node->right->left)) {
            singleLeftShift(node);
        }

        // left skewed
        else {
            singleRightShift(node->right);
            singleLeftShift(node);
        }
    }

    // Left skewed
    else if (factor > 1) {
        if (findHeight(node->left->left) >= findHeight(node->left->right)) {
            singleRightShift(node);
        }

        else {
            singleLeftShift(node->left);
            singleRightShift(node);
        } 
    }

    // Update the height of the node
    node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
    
}



template <typename Comparable>
void AVLTree<Comparable>::singleLeftShift(AVLNode* &node) {

    AVLNode* nodeRight = node->right;

    // Shift left
    node->right = nodeRight->left;
    nodeRight->left = node;

    // Update heights
    node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
    nodeRight->height = max(findHeight(nodeRight->left), findHeight(nodeRight->right)) + 1;

    // Switch spots
    node = nodeRight;

}



template <typename Comparable>
void AVLTree<Comparable>::singleRightShift(AVLNode* &node) {

    AVLNode* nodeLeft = node->left;

    // Shift left
    node->left = nodeLeft->right;
    nodeLeft->right = node;

    // Update heights
    node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
    nodeLeft->height = max(findHeight(nodeLeft->left), findHeight(nodeLeft->right)) + 1;

    // Switch spots
    node = nodeLeft;

}

#endif