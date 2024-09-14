#include "BinarySearchTree.h"

void init(BST ** p_bst) {
    //if use the pointer one level
    //BST * bst;
    //bst = root_node; bst = NULL; the root_node has not been modified.
    //The bst get the pointer of root_node, but this operation only modify the value of bst,
    //can't modify the root_node
    *p_bst = NULL;
}

//1. looking for the appropriate leaf node
//2. insert x to the node left or riht.
void insert(BST ** p_bst, DataType x) {
    //if the tree is empty
    if (p_bst == NULL) {
        printf("The tree is empty!\n");
        return;
    }

    if (*p_bst == NULL) {
        BST * new_node = (BST *)malloc(sizeof (BST));
        new_node->x = x;
        new_node->left = NULL;
        new_node->right = NULL;
        *p_bst = new_node;
    }

    else {
        BST * cur = *p_bst;

        while (cur != NULL) {
            //at right
            if (x > cur->x) {
                cur = cur->right;
            }
            //at left
            else if (x < cur->x) {
                cur = cur->left;
            }
        }

        //insert
        BST * new_node = (BST *)malloc(sizeof (BST));
        new_node->x = x;
        new_node->left = NULL;
        new_node->right = NULL;
        cur = new_node;
    }
}