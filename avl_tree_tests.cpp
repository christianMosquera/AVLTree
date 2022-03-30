#include <iostream>
#include "avl_tree.h"

using std::cout, std::endl;

/*****************************************************
 **
 ** File:    avl_tree_tests.cpp
 ** Project: CSCE 221 Lab 4 Spring 2022
 ** Author:  Christian Mosquera
 ** Date:    03/21/22
 ** Section: 510
 ** Email:   cwbo.1701@tamu.edu
 ** 
 ** This file contains function calls to the avl tree
 ** data structure to test all the functions associated 
 ** with it.
 **
 *****************************************************/

int main() {
    

    //----------------------------------
    //
    // TEST NUMBER 1
    // Purpose: Test default constructor, 
    // insert and print. Print out each
    // step of inserting.
    //
    //----------------------------------

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 1" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// insert and print. Print out each";
    cout << endl << "// step of inserting." << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    AVLTree<int> avl1;

    // Inserting different elements causing shifts
    cout << "// Inserting 10" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(10);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 15" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(15);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 20" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(20);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 16" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(16);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 17" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(17);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 18" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(18);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 19" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(19);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -23" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-23);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -50" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-50);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -2" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-2);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -1" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-1);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 0" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(0);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -10" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-10);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -15" << endl;
    cout << "--------------------------" << endl;
    avl1.insert(-15);
    avl1.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;




    //----------------------------------
    //
    // TEST NUMBER 2
    // Purpose: Test copy constructor, 
    // remove, make_empty and print. Print
    // out each step of removing.
    //
    //----------------------------------

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 2" << endl;
    cout << "// Purpose: Test copy constructor," << endl << "// remove, make_empty and print. Print";
    cout << endl << "// out each step of removing." << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    AVLTree<int> avl2(avl1);


    // removing elements
    cout << "// Starting tree" << endl;
    cout << "--------------------------" << endl;
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 25" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(25);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 10" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(10);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 20" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(20);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 16" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(16);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 17" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(17);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 18" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(18);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 15" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(15);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Removing 19" << endl;
    cout << "--------------------------" << endl;
    avl2.remove(19);
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Making empty" << endl;
    cout << "--------------------------" << endl;
    avl2.make_empty();
    avl2.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;






    //----------------------------------
    //
    // TEST NUMBER 3
    // Purpose: Test copy assignment, 
    // remove, insert and print. Print
    // out each step.
    //
    //----------------------------------


    AVLTree<int> avl3;

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 3" << endl;
    cout << "// Purpose: Test copy assignment," << endl << "// remove, insert, and print. Print";
    cout << endl << "// out each step." << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    cout << "// Inserting 1" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(1);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 5" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(5);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 65" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(65);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 21" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(21);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 72" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(72);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -9" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(-9);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -29" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(-29);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -54" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(-54);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 0" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(0);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 34" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(34);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 65" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(65);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 90" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(90);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Self assignment" << endl;
    cout << "--------------------------" << endl;
    avl3 = avl3;
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// avl3 = avl1" << endl;
    cout << "--------------------------" << endl;
    avl3 = avl1;
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// avl3 = avl2" << endl;
    cout << "--------------------------" << endl;
    avl3 = avl2;
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Insert 0" << endl;
    cout << "--------------------------" << endl;
    avl3.insert(0);
    avl3.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;





    //----------------------------------
    //
    // TEST NUMBER 4
    // Purpose: Test default constructor, 
    // insert, contains, and print. Print 
    // out each step of inserting.
    //
    //----------------------------------

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 4" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// insert, contains, and print. Print";
    cout << endl << "// out each step of inserting." << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;

    AVLTree<int> avl4;


    cout << "// Inserting 10" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(10);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 101" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(101);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 20" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(20);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 16" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(16);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 17" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(17);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 18" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(18);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 19" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(19);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -23" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(-23);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 65" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(65);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -2" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(-2);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 35" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(35);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 0" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(0);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -10" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(-10);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -15" << endl;
    cout << "--------------------------" << endl;
    avl4.insert(-15);
    avl4.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;


    // contains in avl4
    cout << "// Testing avl4 for containing elements:" << endl << endl;
    
    cout << "// Testing 35: ";
    if (avl4.contains(35)) {
        cout << "avl4 contains 35" << endl;
    }
    else{
        cout << "avl4 does not contain 35" << endl;
    }

    cout << "// Testing 76: ";
    if (avl4.contains(76)) {
        cout << "avl4 contains 76" << endl;
    }
    else{
        cout << "avl4 does not contain 76" << endl;
    }
    
    cout << "// Testing 12: ";
    if (avl4.contains(12)) {
        cout << "avl4 contains 12" << endl;
    }
    else{
        cout << "avl4 does not contain 12" << endl;
    }

    cout << "// Testing 67: ";
    if (avl4.contains(67)) {
        cout << "avl4 contains 67" << endl;
    }
    else{
        cout << "avl4 does not contain 67" << endl;
    }

    cout << "// Testing 22: ";
    if (avl4.contains(22)) {
        cout << "avl4 contains 22" << endl;
    }
    else{
        cout << "avl4 does not contain 22" << endl;
    }

    cout << "// Testing 54: ";
    if (avl4.contains(54)) {
        cout << "avl4 contains 54" << endl;
    }
    else{
        cout << "avl4 does not contain 54" << endl;
    }

    cout << "// Testing 101: ";
    if (avl4.contains(101)) {
        cout << "avl4 contains 101" << endl;
    }
    else{
        cout << "avl4 does not contain 101" << endl;
    }

    cout << "// Testing -50: ";
    if (avl4.contains(-50)) {
        cout << "avl4 contains -50" << endl;
    }
    else{
        cout << "avl4 does not contain -50" << endl;
    }

    cout << "// Testing -101: ";
    if (avl4.contains(-101)) {
        cout << "avl4 contains -101" << endl;
    }
    else{
        cout << "avl4 does not contain -101" << endl;
    }

    cout << "// Testing -12: ";
    if (avl4.contains(-12)) {
        cout << "avl4 contains -12" << endl;
    }
    else{
        cout << "avl4 does not contain -12" << endl;
    }

    cout << "// Testing -23: ";
    if (avl4.contains(-23)) {
        cout << "avl4 contains -23" << endl;
    }
    else{
        cout << "avl4 does not contain -23" << endl;
    }

    cout << "// Testing 65: ";
    if (avl4.contains(65)) {
        cout << "avl4 contains 65" << endl;
    }
    else{
        cout << "avl4 does not contain 65" << endl;
    }

    cout << "// Testing 21: ";
    if (avl4.contains(21)) {
        cout << "avl4 contains 21" << endl;
    }
    else{
        cout << "avl4 does not contain 21" << endl;
    }

    cout << endl << endl;





    //----------------------------------
    //
    // TEST NUMBER 5
    // Purpose: Test default constructor, 
    // insert, find_min, and find_max. Print 
    // out each step of inserting.
    //
    //----------------------------------

    cout << endl << "//----------------------------------" << endl << "//" << endl;
    cout << "// TEST NUMBER 5" << endl;
    cout << "// Purpose: Test default constructor," << endl << "// insert, find_min, and find_max. Print";
    cout << endl << "// out each step of inserting." << endl <<"//" << endl;
    cout << "//----------------------------------" << endl << endl;


    AVLTree<int> avl5;

    cout << "// Inserting 19" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(19);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 48" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(48);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 16" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(16);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 99" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(99);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 1" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(1);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 5" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(5);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 65" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(65);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 21" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(21);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting 0" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(0);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -10" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(-10);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;

    cout << "// Inserting -15" << endl;
    cout << "--------------------------" << endl;
    avl5.insert(-15);
    avl5.print_tree();
    cout << "--------------------------" << endl;
    cout << endl;


    // test min and max
    cout << "// Minimum value of avl1: ";
    cout << avl1.find_min() << endl;
    cout << "// Maximum value of avl1: ";
    cout << avl1.find_max() << endl;
    

    try {
        cout << "// Minimum value of avl2: ";
        cout << avl2.find_min() << endl;
        
    }
    catch(std::invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    try{
        cout << "// Maximum value of avl2: ";
        cout << avl2.find_max() << endl;
        cout << endl;
    }
    catch(std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "// Minimum value of avl3: ";
    cout << avl3.find_min() << endl;
    cout << "// Maximum value of avl3: ";
    cout << avl3.find_max() << endl;
    

    cout << "// Minimum value of avl4: ";
    cout << avl4.find_min() << endl;
    cout << "// Maximum value of avl4: ";
    cout << avl4.find_max() << endl;
    

    cout << "// Minimum value of avl5: ";
    cout << avl5.find_min() << endl;
    cout << "// Maximum value of avl5: ";
    cout << avl5.find_max() << endl;
    cout << endl << endl;

    avl1.make_empty();

    // Testing make empty and is empty

    if (avl1.is_empty()) {
        cout << "// avl1 is empty" << endl;
    }
    else{
        cout << "// avl1 is not empty" << endl;
    }

    if (avl2.is_empty()) {
        cout << "// avl2 is empty" << endl;
    }
    else{
        cout << "// avl2 is not empty" << endl;
    }

    if (avl3.is_empty()) {
        cout << "// avl3 is empty" << endl;
    }
    else{
        cout << "// avl3 is not empty" << endl;
    }

    if (avl4.is_empty()) {
        cout << "// avl4 is empty" << endl;
    }
    else{
        cout << "// avl4 is not empty" << endl;
    }

    if (avl5.is_empty()) {
        cout << "// avl5 is empty" << endl;
    }
    else{
        cout << "// avl5 is not empty" << endl;
    }

    cout << endl << endl;


   
}
