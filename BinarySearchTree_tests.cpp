#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <sstream>

using namespace std;

TEST(test_basic) {

    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.size() == 0);
    ASSERT_TRUE(tree.height() == 0);
    ASSERT_TRUE(tree.empty());

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(5);

    cout << "cout << tree.to_string()" << endl;
    cout << tree.to_string() << endl << endl;

    ASSERT_TRUE(tree.size() == 4);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_FALSE(tree.empty());
    

    BinarySearchTree<int> skew_right_tree;
    skew_right_tree.insert(1);
    skew_right_tree.insert(2);
    skew_right_tree.insert(4);
    cout << "cout << skew_right_tree.to_string()" << endl;
    cout << skew_right_tree.to_string() << endl << endl;
    ASSERT_TRUE(skew_right_tree.size() == 3);
    ASSERT_TRUE(skew_right_tree.height() == 3);
    ASSERT_FALSE(skew_right_tree.empty());

    BinarySearchTree<int> skew_left_tree;
    skew_left_tree.insert(4);
    skew_left_tree.insert(2);
    skew_left_tree.insert(1);
    cout << "cout << skew_left_tree.to_string()" << endl;
    cout << skew_left_tree.to_string() << endl << endl;
    ASSERT_TRUE(skew_left_tree.size() == 3);
    ASSERT_TRUE(skew_left_tree.height() == 3);
    ASSERT_FALSE(skew_left_tree.empty());

}

TEST(test_copy){
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.size() == 0);
    ASSERT_TRUE(tree.height() == 0);
    ASSERT_TRUE(tree.empty());

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(5);

    cout << "cout << tree.to_string()" << endl;
    cout << tree.to_string() << endl << endl;

    //test copy ctor 
    BinarySearchTree<int> copy_tree = tree;
    ASSERT_TRUE(copy_tree.size() == 4);
    ASSERT_TRUE(copy_tree.height() == 3);
    ASSERT_FALSE(copy_tree.empty());
    cout << "cout << copy_tree.to_string()" << endl;
    cout << copy_tree.to_string() << endl << endl;

    tree.insert(8);

    ASSERT_TRUE(tree.size() == 5);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_FALSE(tree.empty());

    //test assign empty
    BinarySearchTree<int> ass_tree;
    ASSERT_TRUE(ass_tree.size() == 0);
    ASSERT_TRUE(ass_tree.height() == 0);
    ASSERT_TRUE(ass_tree.empty());

    ass_tree = tree;
    ASSERT_EQUAL(ass_tree.size(), 5);
    ASSERT_EQUAL(ass_tree.height(), 3);
    ASSERT_FALSE(ass_tree.empty());
    cout << "cout << ass_tree.to_string()" << endl;
    cout << ass_tree.to_string() << endl << endl;

}

TEST(test_insert_compex){
    BinarySearchTree<int> tree1;
    auto returned = tree1.insert(6);
    ASSERT_EQUAL(*returned, 6);
    returned = tree1.insert(7);
    ASSERT_EQUAL(*returned, 7);
    tree1.insert(9);
    tree1.insert(1);
    tree1.insert(5);
    tree1.insert(2);
    returned = tree1.insert(10);
    ASSERT_EQUAL(*returned, 10);

    cout << "cout << tree1.to_string()" << endl;
    cout << tree1.to_string() << endl << endl;

    BinarySearchTree<int> tree2;
    tree2.insert(6);
    tree2.insert(5);
    tree2.insert(9);
    tree2.insert(7);
    tree2.insert(10);
    tree2.insert(1);
    tree2.insert(2);
    cout << "cout << tree2.to_string()" << endl;
    cout << tree2.to_string() << endl << endl;

}

// TEST(test_copy){
//     //copy basic

//     //copy empty

//     //copy single 

//     //copy skew_right 

//     //copy skew_left

// }

// TEST(test_find){
//     //find first

//     //find terminal 

//     //find single

// }

TEST(test_min_max){
    //max elt first
    BinarySearchTree<int> tree_maxfirst;
    tree_maxfirst.insert(10);
    tree_maxfirst.insert(5);
    tree_maxfirst.insert(9);
    tree_maxfirst.insert(8);
    tree_maxfirst.insert(2);

    ASSERT_EQUAL(*tree_maxfirst.max_element(), 10);

    //max elt terminal 
    BinarySearchTree<int> tree_maxlast;
    tree_maxlast.insert(5);
    tree_maxlast.insert(9);
    tree_maxlast.insert(8);
    tree_maxlast.insert(2);
    tree_maxlast.insert(10);

    ASSERT_EQUAL(*tree_maxlast.max_element(), 10);


    //max elt middle 
    BinarySearchTree<int> tree_maxmid;
    tree_maxmid.insert(5);
    tree_maxmid.insert(9);
    tree_maxmid.insert(8);
    tree_maxmid.insert(2);
    
    ASSERT_EQUAL(*tree_maxmid.max_element(), 9);

    //max / min elt empty
    BinarySearchTree<int> tree_empty;
    ASSERT_EQUAL(tree_empty.max_element(), tree_empty.end());
    ASSERT_EQUAL(tree_empty.min_element(), tree_empty.end());  
    


    //min elt first
    BinarySearchTree<int> skew_right_tree;
    skew_right_tree.insert(1);
    skew_right_tree.insert(2);
    skew_right_tree.insert(4);
    ASSERT_EQUAL(*skew_right_tree.min_element(), 1);

    //min elt terminal
    ASSERT_EQUAL(*tree_maxmid.min_element(), 2);

    //min elt mid
    BinarySearchTree<int> tree_minmid;
    tree_minmid.insert(6);
    tree_minmid.insert(2);
    tree_minmid.insert(5);
    tree_minmid.insert(8);
    ASSERT_EQUAL(*tree_minmid.min_element(), 2);

}

// TEST(test_check_sort){

// }

// TEST(test_min_great){
    
// }

TEST_MAIN()
