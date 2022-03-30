#include <iostream>
#include "binary_search_tree.h"

using std::cout;
using std::endl;

/*****************************************************
 **
 ** File:    binary_search_tree_tests.cpp
 ** Project: CSCE 221 Lab 4 Spring 2022
 ** Author:  Christian Mosquera
 ** Date:    03/21/22
 ** Section: 510
 ** Email:   cwbo.1701@tamu.edu
 ** 
 ** This file contains function calls to the binary
 ** search tree data structure to test all the
 ** functions associated with it.
 **
 *****************************************************/

int main() {

    //----------------------------------
    //
    // TEST NUMBER 1
    // Purpose: Test default constructor, 
    // copy constructor, insert, remove,
    // and print.
    //
    //----------------------------------

    // Making tree1
    BinarySearchTree<int> tree1;
    tree1.insert(20);
    tree1.insert(10);
    tree1.insert(30);
    tree1.insert(40);
    tree1.insert(35);
    tree1.insert(35);
    tree1.insert(45);
    tree1.insert(37);
    
    std::cout << std::endl << "//----------------------------------" << std::endl << "//" << std::endl;
    std::cout << "// TEST NUMBER 1" << std::endl;
    std::cout << "// Purpose: Test default constructor," << std::endl << "// copy constructor, insert, remove,";
    cout << std::endl << "// and print" << std::endl <<"//" << std::endl;
    std::cout << "//----------------------------------" << std::endl << std::endl;

    // Printing tree1 before
    cout << "// Before changes to tree1: " << endl << endl;
    tree1.print_tree();

    // Making tree2
    BinarySearchTree<int> tree2(tree1);
    

    // Changing tree1 and tree2 to ensure they are different
    
    tree1.remove(35);
    tree2.remove(40);
    tree2.remove(40);
    BinarySearchTree<int> tree14(tree1);
    tree14.insert(35);
    tree14.remove(40);

    // Printing out after changes
    std::cout << endl;
    cout << "// After changes to tree1:" << endl << endl;
    tree1.print_tree();
    std::cout << endl;
    cout << "// After changes to tree2:" << endl << endl;
    tree2.print_tree();
    cout << endl;
    cout << "// After changes to tree14:" << endl << endl;
    tree14.print_tree();
    cout << endl;



    //----------------------------------
    //
    // TEST NUMBER 2
    // Purpose: Test default constructor, 
    // copy assignment, insert, remove,
    // and print.
    //
    //----------------------------------
    
    // Making tree3
    BinarySearchTree<int> tree3;
    tree3.insert(32);
    tree3.insert(10);
    tree3.insert(14);
    tree3.insert(5);
    tree3.insert(51);
    tree3.insert(49);
    tree3.insert(16);
    tree3.insert(21);

    std::cout << std::endl << "//----------------------------------" << std::endl << "//" << std::endl;
    std::cout << "// TEST NUMBER 2" << std::endl;
    std::cout << "// Purpose: Test default constructor," << std::endl << "// copy assignment, insert, remove,";
    cout << std::endl << "// and print" << std::endl <<"//" << std::endl;
    std::cout << "//----------------------------------" << std::endl << std::endl;

    // Print tree3 before changes
    cout << "// Before changes to tree3: " << endl << endl;
    tree3.print_tree();

    // Reusing tree1
    tree1 = tree3;

    // Change tree3
    tree3.remove(49);
    tree1.insert(-1);

    // Printing out tree1 and tree3 after changes
    std::cout << endl;
    cout << "// After changes to tree1:" << endl << endl;
    tree1.print_tree();
    std::cout << endl;
    cout << "// After changes to tree3:" << endl << endl;
    tree3.print_tree();
    cout << endl;


    //----------------------------------
    //
    // TEST NUMBER 3
    // Purpose: Test default constructor, 
    // copy assignment, insert, remove,
    // and print. This time all empty trees.
    //
    //----------------------------------

    // Make tree4, tree5, and tree6
    BinarySearchTree<int> tree4;
    BinarySearchTree<int> tree5(tree4);
    BinarySearchTree<int> tree6;
    tree6.insert(5);

    std::cout << std::endl << "//----------------------------------" << std::endl << "//" << std::endl;
    std::cout << "// TEST NUMBER 3" << std::endl;
    std::cout << "// Purpose: Test default constructor," << std::endl << "// copy assignment, insert, remove,";
    cout << std::endl << "// and print. This time all empty trees." << std::endl <<"//" << std::endl;
    std::cout << "//----------------------------------" << std::endl << std::endl;

    // Print before changes
    cout << "// Before changes to tree4: " << endl << endl;
    tree4.print_tree();
    cout << "// Before changes to tree5: " << endl << endl;
    tree5.print_tree();
    cout << "// Before changes to tree6: " << endl << endl;
    tree6.print_tree();

    // Self assign and copy assignment
    tree5 = tree5;
    tree4 = tree5;
    tree6 = tree4;

    // Print after changes
    cout << endl;
    cout << "// After changes to tree4:" << endl << endl;
    tree4.print_tree();
    cout << "// After changes to tree5:" << endl << endl;
    tree5.print_tree();
    cout << "// After changes to tree6:" << endl << endl;
    tree6.print_tree();
    cout << endl;


    //----------------------------------
    //
    // TEST NUMBER 4
    // Purpose: Test default constructor, 
    // contains, insert, remove, and print.
    //
    //----------------------------------


    // Make tree7
    BinarySearchTree<int> tree7;
    tree7.insert(43);
    tree7.insert(4);
    tree7.insert(29);
    tree7.insert(35);
    tree7.insert(42);
    tree7.insert(99);
    tree7.insert(31);
    

    std::cout << "//----------------------------------" << std::endl << "//" << std::endl;
    std::cout << "// TEST NUMBER 4" << std::endl;
    std::cout << "// Purpose: Test default constructor," << std::endl << "// contains, insert, remove, and print.";
    cout << std::endl <<"//" << std::endl;
    std::cout << "//----------------------------------" << std::endl << std::endl;


    // Print out the tree
    cout << "// tree7:" << endl << endl;
    tree7.print_tree();
    cout << endl;

    // Does contain check
    cout << "// Testing 35: ";
    if (tree7.contains(35)) {
        cout << "tree7 contains 35" << endl;
    }
    else{
        cout << "tree7 does not contain 35" << endl;
    }

    // Does not contain check
    cout << "// Testing 100: ";
    if (tree7.contains(100)) {
        cout << "tree7 contains 100" << endl;
    }
    else {
        cout << "tree7 does not contain 100" << endl;
    }
    cout << endl;


    //----------------------------------
    //
    // TEST NUMBER 5
    // Purpose: Test default constructor, 
    // find_max, find_min, insert, remove, 
    // and print.
    //
    //----------------------------------

    BinarySearchTree<int> tree8;
    BinarySearchTree<int> tree9;
    BinarySearchTree<int> tree10;
    BinarySearchTree<int> tree11;

    // Empty tree
    BinarySearchTree<int> tree12;

    // Right skewed tree
    tree8.insert(10);
    tree8.insert(15);
    tree8.insert(20);

    // Left skewed tree
    tree9.insert(5);
    tree9.insert(0);
    tree9.insert(-5);

    // Single node tree
    tree10.insert(20);

    // Normal tree
    tree11.insert(20);
    tree11.insert(10);
    tree11.insert(5);
    tree11.insert(8);
    tree11.insert(30);
    tree11.insert(25);
    tree11.insert(40);
    tree11.insert(-1);


    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 5" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// find_max, find_min, insert, remove," << endl;
    cout << "// and print.";
    cout << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    // Print trees
    cout << "// tree8:" << endl << endl;
    tree8.print_tree();
    cout << endl;

    cout << "// tree9:" << endl << endl;
    tree9.print_tree();
    cout << endl;

    cout << "// tree10:" << endl << endl;
    tree10.print_tree();
    cout << endl;

    cout << "// tree11:" << endl << endl;
    tree11.print_tree();
    cout << endl;

    cout << "// tree12:" << endl << endl;
    tree12.print_tree();
    cout << endl;


    // Find min and max
    cout << "// Minimum value of tree8: ";
    cout << tree8.find_min() << endl;
    cout << "// Maximum value of tree8: ";
    cout << tree8.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree9: ";
    cout << tree9.find_min() << endl;
    cout << "// Maximum value of tree9: ";
    cout << tree9.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree10: ";
    cout << tree10.find_min() << endl;
    cout << "// Maximum value of tree10: ";
    cout << tree10.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree11: ";
    cout << tree11.find_min() << endl;
    cout << "// Maximum value of tree11: ";
    cout << tree11.find_max() << endl;
    cout << endl;

    // Tree12 empty error check
    try {
        cout << "// Minimum value of tree12: ";
        cout << tree12.find_min() << endl;
    }
    catch (std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "// Maximum value of tree12: ";
        cout << tree12.find_max() << endl;
    }
    catch (std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl;


    //----------------------------------
    //
    // TEST NUMBER 6
    // Purpose: Test default constructor, 
    // is_empty, make_empty, insert, remove, 
    // and print.
    //
    //----------------------------------

    // Make tree13
    BinarySearchTree<int> tree13;
    tree13.insert(12);
    tree13.insert(14);
    tree13.insert(5);
    tree13.insert(2);
    tree13.insert(7);
    tree13.insert(22);
    tree13.insert(17);
    tree13.insert(49);


    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 6" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// make_empty, is_empty, insert, remove," << endl;
    cout << "// and print.";
    cout << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    // Print tree13
    cout << "// tree13:" << endl << endl;
    tree13.print_tree();
    cout << endl;

    // Check if empty
    if (tree13.is_empty()) {
        cout << "// Tree is empty" << endl;
    }
    else {
        cout << "// Tree is not empty" << endl;
    }

    // Make tree13 empty
    tree13.make_empty();
    if (tree13.is_empty()) {
        cout << "// Tree is empty" << endl;
    }
    else {
        cout << "// Tree is not empty" << endl;
    }
    cout << endl;



    //----------------------------------
    //
    // TEST NUMBER 7
    // Purpose: Test a bunch of different 
    // binary trees.
    //
    //----------------------------------


    // Making tree15
    BinarySearchTree<int> tree15;
    tree15.insert(34);
    tree15.insert(12);
    tree15.insert(23);
    tree15.insert(54);
    tree15.insert(21);
    tree15.insert(4);
    tree15.insert(45);
    tree15.remove(54);

    // Make tree16 big
    BinarySearchTree<int> tree16(tree15);

    tree16.insert(34);
    tree16.insert(12);
    tree16.insert(23);
    tree16.insert(54);
    tree16.insert(21);
    tree16.insert(4);
    tree16.insert(45);
    tree16.insert(49);
    tree16.insert(75);
    tree16.insert(1);
    tree16.insert(2);
    tree16.insert(3);
    tree16.insert(5);
    tree16.insert(9);
    tree16.insert(65);
    tree16.insert(24);
    tree16.insert(17);
    tree16.insert(95);

    // tree17 even bigger
    BinarySearchTree<int> tree17(tree16);

    tree17.insert(81);
    tree17.insert(95);
    tree17.insert(64);
    tree17.insert(15);
    tree17.insert(71);
    tree17.insert(11);
    tree17.insert(39);
    tree17.insert(31);
    tree17.insert(51);
    tree17.insert(61);
    tree17.insert(82);
    tree17.insert(99);
    tree17.insert(100);
    tree17.insert(46);
    tree17.insert(78);
    tree17.insert(97);
    tree17.insert(38);
    tree17.insert(83);
    tree17.insert(23);
    tree17.insert(101);

    // tree18 even bigger with negative numbers
    BinarySearchTree<int> tree18(tree17);
    tree18.insert(-50);
    tree18.insert(-95);
    tree18.insert(-64);
    tree18.insert(-15);
    tree18.insert(-71);
    tree18.insert(-11);
    tree18.insert(-39);
    tree18.insert(-31);
    tree18.insert(-51);
    tree18.insert(-61);
    tree18.insert(-82);
    tree18.insert(-99);
    tree18.insert(-100);
    tree18.insert(-46);
    tree18.insert(-78);
    tree18.insert(-97);
    tree18.insert(-38);
    tree18.insert(-83);
    tree18.insert(-23);
    tree18.insert(-101);

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 7" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// make_empty, is_empty, insert, remove," << endl;
    cout << "// and print.";
    cout << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;

    // print out tree 15
    cout << "// tree15:" << endl << endl;
    tree15.print_tree();
    cout << endl;

    // print out tree 16
    cout << "// tree16:" << endl << endl;
    tree16.print_tree();
    cout << endl;

    // print out tree 17
    cout << "// tree17:" << endl << endl;
    tree17.print_tree();
    cout << endl;

    // print out tree 18
    cout << "// tree18:" << endl << endl;
    tree18.print_tree();
    cout << endl;

    // test min and max
    cout << "// Minimum value of tree15: ";
    cout << tree15.find_min() << endl;
    cout << "// Maximum value of tree15: ";
    cout << tree15.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree16: ";
    cout << tree16.find_min() << endl;
    cout << "// Maximum value of tree16: ";
    cout << tree16.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree17: ";
    cout << tree17.find_min() << endl;
    cout << "// Maximum value of tree17: ";
    cout << tree17.find_max() << endl;
    cout << endl;

    cout << "// Minimum value of tree18: ";
    cout << tree18.find_min() << endl;
    cout << "// Maximum value of tree18: ";
    cout << tree18.find_max() << endl;
    cout << endl << endl;


    // Does contain check
    cout << "// Testing tree15 for containing elements:" << endl << endl;
    
    cout << "// Testing 35: ";
    if (tree15.contains(35)) {
        cout << "tree15 contains 35" << endl;
    }
    else{
        cout << "tree15 does not contain 35" << endl;
    }

    cout << "// Testing 76: ";
    if (tree15.contains(76)) {
        cout << "tree15 contains 76" << endl;
    }
    else{
        cout << "tree15 does not contain 76" << endl;
    }
    
    cout << "// Testing 12: ";
    if (tree15.contains(12)) {
        cout << "tree15 contains 12" << endl;
    }
    else{
        cout << "tree15 does not contain 12" << endl;
    }

    cout << "// Testing 67: ";
    if (tree15.contains(67)) {
        cout << "tree15 contains 67" << endl;
    }
    else{
        cout << "tree15 does not contain 67" << endl;
    }

    cout << "// Testing 22: ";
    if (tree15.contains(22)) {
        cout << "tree15 contains 22" << endl;
    }
    else{
        cout << "tree15 does not contain 22" << endl;
    }

    cout << "// Testing 54: ";
    if (tree15.contains(54)) {
        cout << "tree15 contains 54" << endl;
    }
    else{
        cout << "tree15 does not contain 54" << endl;
    }

    cout << "// Testing 101: ";
    if (tree15.contains(101)) {
        cout << "tree15 contains 101" << endl;
    }
    else{
        cout << "tree15 does not contain 101" << endl;
    }

    cout << "// Testing -50: ";
    if (tree15.contains(-50)) {
        cout << "tree15 contains -50" << endl;
    }
    else{
        cout << "tree15 does not contain -50" << endl;
    }

    cout << "// Testing -101: ";
    if (tree15.contains(-101)) {
        cout << "tree15 contains -101" << endl;
    }
    else{
        cout << "tree15 does not contain -101" << endl;
    }

    cout << "// Testing -12: ";
    if (tree15.contains(-12)) {
        cout << "tree15 contains -12" << endl;
    }
    else{
        cout << "tree15 does not contain -12" << endl;
    }

    cout << "// Testing -23: ";
    if (tree15.contains(-23)) {
        cout << "tree15 contains -23" << endl;
    }
    else{
        cout << "tree15 does not contain -23" << endl;
    }

    cout << "// Testing 65: ";
    if (tree15.contains(65)) {
        cout << "tree15 contains 65" << endl;
    }
    else{
        cout << "tree15 does not contain 65" << endl;
    }

    cout << "// Testing 21: ";
    if (tree15.contains(21)) {
        cout << "tree15 contains 21" << endl;
    }
    else{
        cout << "tree15 does not contain 21" << endl;
    }

    cout << endl << endl;



    cout << "// Testing tree16 for containing elements:" << endl << endl;
    
    cout << "// Testing 35: ";
    if (tree16.contains(35)) {
        cout << "tree16 contains 35" << endl;
    }
    else{
        cout << "tree16 does not contain 35" << endl;
    }

    cout << "// Testing 76: ";
    if (tree16.contains(76)) {
        cout << "tree16 contains 76" << endl;
    }
    else{
        cout << "tree16 does not contain 76" << endl;
    }
    
    cout << "// Testing 12: ";
    if (tree16.contains(12)) {
        cout << "tree16 contains 12" << endl;
    }
    else{
        cout << "tree16 does not contain 12" << endl;
    }

    cout << "// Testing 67: ";
    if (tree16.contains(67)) {
        cout << "tree16 contains 67" << endl;
    }
    else{
        cout << "tree16 does not contain 67" << endl;
    }

    cout << "// Testing 22: ";
    if (tree16.contains(22)) {
        cout << "tree16 contains 22" << endl;
    }
    else{
        cout << "tree16 does not contain 22" << endl;
    }

    cout << "// Testing 54: ";
    if (tree16.contains(54)) {
        cout << "tree16 contains 54" << endl;
    }
    else{
        cout << "tree16 does not contain 54" << endl;
    }

    cout << "// Testing 101: ";
    if (tree16.contains(101)) {
        cout << "tree16 contains 101" << endl;
    }
    else{
        cout << "tree16 does not contain 101" << endl;
    }

    cout << "// Testing -50: ";
    if (tree16.contains(-50)) {
        cout << "tree16 contains -50" << endl;
    }
    else{
        cout << "tree16 does not contain -50" << endl;
    }

    cout << "// Testing -101: ";
    if (tree16.contains(-101)) {
        cout << "tree16 contains -101" << endl;
    }
    else{
        cout << "tree16 does not contain -101" << endl;
    }

    cout << "// Testing -12: ";
    if (tree16.contains(-12)) {
        cout << "tree16 contains -12" << endl;
    }
    else{
        cout << "tree16 does not contain -12" << endl;
    }

    cout << "// Testing -23: ";
    if (tree16.contains(-23)) {
        cout << "tree16 contains -23" << endl;
    }
    else{
        cout << "tree16 does not contain -23" << endl;
    }

    cout << "// Testing 65: ";
    if (tree16.contains(65)) {
        cout << "tree16 contains 65" << endl;
    }
    else{
        cout << "tree16 does not contain 65" << endl;
    }

    cout << "// Testing 21: ";
    if (tree16.contains(21)) {
        cout << "tree16 contains 21" << endl;
    }
    else{
        cout << "tree16 does not contain 21" << endl;
    }

    cout << endl << endl;


    cout << "// Testing tree17 for containing elements:" << endl << endl;
    
    cout << "// Testing 35: ";
    if (tree17.contains(35)) {
        cout << "tree17 contains 35" << endl;
    }
    else{
        cout << "tree17 does not contain 35" << endl;
    }

    cout << "// Testing 76: ";
    if (tree17.contains(76)) {
        cout << "tree17 contains 76" << endl;
    }
    else{
        cout << "tree17 does not contain 76" << endl;
    }
    
    cout << "// Testing 12: ";
    if (tree17.contains(12)) {
        cout << "tree17 contains 12" << endl;
    }
    else{
        cout << "tree17 does not contain 12" << endl;
    }

    cout << "// Testing 67: ";
    if (tree17.contains(67)) {
        cout << "tree17 contains 67" << endl;
    }
    else{
        cout << "tree17 does not contain 67" << endl;
    }

    cout << "// Testing 22: ";
    if (tree17.contains(22)) {
        cout << "tree17 contains 22" << endl;
    }
    else{
        cout << "tree17 does not contain 22" << endl;
    }

    cout << "// Testing 54: ";
    if (tree17.contains(54)) {
        cout << "tree17 contains 54" << endl;
    }
    else{
        cout << "tree17 does not contain 54" << endl;
    }

    cout << "// Testing 101: ";
    if (tree17.contains(101)) {
        cout << "tree17 contains 101" << endl;
    }
    else{
        cout << "tree17 does not contain 101" << endl;
    }

    cout << "// Testing -50: ";
    if (tree17.contains(-50)) {
        cout << "tree17 contains -50" << endl;
    }
    else{
        cout << "tree17 does not contain -50" << endl;
    }

    cout << "// Testing -101: ";
    if (tree17.contains(-101)) {
        cout << "tree17 contains -101" << endl;
    }
    else{
        cout << "tree17 does not contain -101" << endl;
    }

    cout << "// Testing -12: ";
    if (tree17.contains(-12)) {
        cout << "tree17 contains -12" << endl;
    }
    else{
        cout << "tree17 does not contain -12" << endl;
    }

    cout << "// Testing -23: ";
    if (tree17.contains(-23)) {
        cout << "tree17 contains -23" << endl;
    }
    else{
        cout << "tree17 does not contain -23" << endl;
    }

    cout << "// Testing 65: ";
    if (tree17.contains(65)) {
        cout << "tree17 contains 65" << endl;
    }
    else{
        cout << "tree17 does not contain 65" << endl;
    }

    cout << "// Testing 21: ";
    if (tree17.contains(21)) {
        cout << "tree17 contains 21" << endl;
    }
    else{
        cout << "tree17 does not contain 21" << endl;
    }

    cout << endl << endl;


    cout << "// Testing tree18 for containing elements:" << endl << endl;
    
    cout << "// Testing 35: ";
    if (tree18.contains(35)) {
        cout << "tree18 contains 35" << endl;
    }
    else{
        cout << "tree18 does not contain 35" << endl;
    }

    cout << "// Testing 76: ";
    if (tree18.contains(76)) {
        cout << "tree18 contains 76" << endl;
    }
    else{
        cout << "tree18 does not contain 76" << endl;
    }
    
    cout << "// Testing 12: ";
    if (tree18.contains(12)) {
        cout << "tree18 contains 12" << endl;
    }
    else{
        cout << "tree18 does not contain 12" << endl;
    }

    cout << "// Testing 67: ";
    if (tree18.contains(67)) {
        cout << "tree18 contains 67" << endl;
    }
    else{
        cout << "tree18 does not contain 67" << endl;
    }

    cout << "// Testing 22: ";
    if (tree18.contains(22)) {
        cout << "tree18 contains 22" << endl;
    }
    else{
        cout << "tree18 does not contain 22" << endl;
    }

    cout << "// Testing 54: ";
    if (tree18.contains(54)) {
        cout << "tree18 contains 54" << endl;
    }
    else{
        cout << "tree18 does not contain 54" << endl;
    }

    cout << "// Testing 101: ";
    if (tree18.contains(101)) {
        cout << "tree18 contains 101" << endl;
    }
    else{
        cout << "tree18 does not contain 101" << endl;
    }

    cout << "// Testing -50: ";
    if (tree18.contains(-50)) {
        cout << "tree18 contains -50" << endl;
    }
    else{
        cout << "tree18 does not contain -50" << endl;
    }

    cout << "// Testing -101: ";
    if (tree18.contains(-101)) {
        cout << "tree18 contains -101" << endl;
    }
    else{
        cout << "tree18 does not contain -101" << endl;
    }

    cout << "// Testing -12: ";
    if (tree18.contains(-12)) {
        cout << "tree18 contains -12" << endl;
    }
    else{
        cout << "tree18 does not contain -12" << endl;
    }

    cout << "// Testing -23: ";
    if (tree18.contains(-23)) {
        cout << "tree18 contains -23" << endl;
    }
    else{
        cout << "tree18 does not contain -23" << endl;
    }

    cout << "// Testing 65: ";
    if (tree18.contains(65)) {
        cout << "tree18 contains 65" << endl;
    }
    else{
        cout << "tree18 does not contain 65" << endl;
    }

    cout << "// Testing 21: ";
    if (tree18.contains(21)) {
        cout << "tree18 contains 21" << endl;
    }
    else{
        cout << "tree18 does not contain 21" << endl;
    }

    cout << endl << endl;


    // Testing make empty and is empty
    tree15.make_empty();
    tree16.make_empty();

    if (tree15.is_empty()) {
        cout << "// tree15 is empty" << endl;
    }
    else{
        cout << "// tree15 is not empty" << endl;
    }

    if (tree16.is_empty()) {
        cout << "// tree16 is empty" << endl;
    }
    else{
        cout << "// tree16 is not empty" << endl;
    }

    if (tree17.is_empty()) {
        cout << "// tree17 is empty" << endl;
    }
    else{
        cout << "// tree17 is not empty" << endl;
    }

    if (tree18.is_empty()) {
        cout << "// tree18 is empty" << endl;
    }
    else{
        cout << "// tree18 is not empty" << endl;
    }

    cout << endl << endl;

}
