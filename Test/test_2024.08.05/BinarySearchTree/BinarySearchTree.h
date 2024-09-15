#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct BSTNode {
    DataType x;
    struct BSTNode * left;
    struct BSTNode * right;
}BST;

//p_bst is the pointer to bst (root node desu)
void init(BST ** p_bst);

//insert x into the p_bst tree
void insert(BST ** p_bst, DataType x);