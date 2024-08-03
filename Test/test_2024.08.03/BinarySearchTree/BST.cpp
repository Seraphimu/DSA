#include "BST.hpp"

TN * BST::insertBST(DataType x, TN *& root) {
    if (root == nullptr) {
        root = new TN(x);
    }
    // at right
    else if(x > root->data) {
        root->right = insertBST(x, root->right);
    }
    // at left
    else if (x < root->data) {
        root->left = insertBST(x, root->left);
    }
    // x == root->data
    // do nothing
    else {
        cout << x << " is exist!\n";
    }

    return root;
}

void BST::insertBST(DataType x) {
    insertBST(x, root);
    cout << x << "has been inserted!\n";
}


TN * BST::deleteBST(DataType x, TN *& root) {
    TN * tmp = nullptr;
    if (root == nullptr) {
        cout << "Tree is empty!\n";
    }
    //value at right
    else if (x > root->data) {
        root->right = deleteBST(x, root->right);
    }
    // at left
    else if (x < root->data) {
        root->left = deleteBST(x, root->left);
    }
    // x == root->data
    else {
        //two children
        if (root->left != nullptr && root->right != nullptr) {
            tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = deleteBST(root->data, root->right);
        }
        // single child or not exist child
        else {
            tmp = root;
            if (root->left == nullptr) {
                root = root->right;
            }
            else if (root->right == nullptr) {
                root = root->left;
            }

            delete tmp;
            tmp = nullptr;
        }
    }

    return root;
}

void BST::deleteBST (DataType x) {
    deleteBST(x, root);
    cout << x << " has been deleted!\n";
}

TN * BST::findMin(TN * root) {
    if (root == nullptr) {
        cout << "Tree is Empty!\n";
        return nullptr;
    }
    else {
        TN * minNode = root;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
        }
        return minNode;
    }
}

TN * BST::findMin() {
    return findMin(root);
}


void BST::levelTraverse(TN * root) {
    if (root == nullptr) {
        return;
    }

    //建立一个存放Node*型数据的队列
    queue<TN *> qn;
    TN * cur;
    //根节点先进队列
    qn.push(root);

    //队列非空时持续循环
    while (!qn.empty()) {
        //获取队头指针
        cur = qn.front();
        //输出队头元素
        cout << cur->data << " ";
        //判断是否有子节点，有则入队
        if (cur->left != nullptr) {
            qn.push(cur->left);
        }
        if (cur->right != nullptr) {
            qn.push(cur->right);
        }
        //把队头元素出队
        qn.pop();
    }
}

void BST::levelTraverse() {
    cout << "Level Traverse is: \n";
    levelTraverse(root);
    cout << "\n";
}

void BST::preOrderTraverse(TN * root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void BST::preOrderTraverse() {
    cout << "Pre Order Traverse is: \n";
    preOrderTraverse(root);
    cout << "\n";
}

void BST::makeEmpty(TN * root) {
    if (root == nullptr) {
        cout << "Tree is empty!\n";
        return;
    }

    //建立一个存放Node*型数据的队列
    queue<TN *> qn;
    TN * cur;
    //根节点先进队列
    qn.push(root);

    //队列非空时持续循环
    while (!qn.empty()) {
        //获取队头指针
        cur = qn.front();
        //输出队头元素
        cout << cur->data << " ";
        //判断是否有子节点，有则入队
        if (cur->left != nullptr) {
            qn.push(cur->left);
        }
        if (cur->right != nullptr) {
            qn.push(cur->right);
        }

        //把队头元素出队
        delete cur;
        cur = nullptr;
        cout << "has been erased!\n";
        qn.pop();
    }
}

void BST::makeEmpty() {
    makeEmpty(root);
}







