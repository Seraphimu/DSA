#include "BinarySearchTree.hpp"

void BST::preOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void BST::preOrderTraverse() {
    preOrderTraverse(root);
    cout << "\n";
}


void BST::inOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
}

void BST::inOrderTraverse() {
    inOrderTraverse(root);
    cout << "\n";
}


void BST::postOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " ";
}

void BST::postOrderTraverse() {
    postOrderTraverse(root);
    cout << "\n";
}