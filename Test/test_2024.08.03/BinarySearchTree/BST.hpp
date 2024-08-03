#include <iostream>
#include <queue>

using namespace std;

typedef int DataType;

// The node of tree;
typedef class TreeNode {
private:
    DataType data;
    TreeNode * left;
    TreeNode * right;

    TreeNode(DataType x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
    friend class BinarySearchTree;
}TN;

// Root of tree and the method that operate tree;
typedef class BinarySearchTree {
private:
    TN * root;
    // Insert the element x at the appropriate position.
    // change the value of root should use the operator *& or **
    TN * insertBST(DataType x, TN *& root);
    // Delete the element x in the tree
    TN * deleteBST(DataType x, TN *& root);
    // Search the min element in the tree, and return the node;
    TN * findMin(TN * root);
    
    void levelTraverse(TN * root);
    void preOrderTraverse(TN * root);
    void makeEmpty(TN * root);
public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertBST(DataType x);
    void deleteBST(DataType x);
    TN * findMin();

    void levelTraverse();
    void preOrderTraverse();
    void makeEmpty();
}BST;