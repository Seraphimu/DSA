#include "BinarySearchTree.hpp"

void BST::createManual() {
    //创建一个节点，并初始化为空
    Node * node_0 = new Node();
    node_0->data = 514;
    
    Node * node_1 = new Node();
    node_1->data = 114;
    
    Node * node_2 = new Node();
    node_2->data = 1919;

    Node * node_3 = new Node();
    node_3->data = 810;

    Node * node_4 = new Node();
    node_4->data = 114514;

    Node * node_5 = new Node();
    node_5->data = 1919810;

    //手动构建
    node_3->left = node_0;
    node_3->right = node_2;

    node_0->left = node_1;

    node_2->right = node_4;

    node_4->right = node_5;

    root = node_3;
}

Node * BST::searchByIter(Node * root, DataType target) {
    while (root != nullptr) {
        //目标值比当前值大，往右走
        if (target > root->data) {
            root = root->right;
        }
        //目标值比当前值小，往左走
        else if (target < root->data) {
            root = root->left;
        }
        //不大不小，刚刚好
        else {
            return root;
        }
    }
    
    //如果元素在树中，在前面循环执行的过程中就会返回，如果程序走到这里，就说明树中不存在该目标元素，返回空
    return nullptr;
}

void BST::searchByIter(DataType target) {
    Node * ret = searchByIter(root, target);
    if (ret != nullptr) {
        cout << target << " at " << ret << "\n";
    }
    else {
        cout << target << " is not exist in tree!\n";
    }
}

DataType BST::getMax(Node * root) {
   	//寻找树最左端的值，即最小值
	while (root->right != nullptr) {
        root = root->right;
    }
    
    return root->data;
}

DataType BST::getMax() {
    return getMax(root);
}

DataType BST::getMin(Node * root) {
    while (root->left != nullptr) {
        root = root->left;
    }

    return root->data;
}

DataType BST::getMin() {
    return getMin(root);
}

Node * BST::insert(Node *& root, DataType target) {
    //为空，分配一个空间
    if (root == nullptr) {
		root = new Node();
        root->data = target;
        root->left = root->right = nullptr;
    }
    //比当前节点值小，向左找节点插入
    else if (target < root->data) {
        root->left = insert(root->left, target);
    }
    //比当前节点值大，向右找节点插入
    else if (target > root->data) {
        root->right = insert(root->right, target);
    }
    //else target存在，什么都不做
    return root;
}

void BST::insert(DataType target) {
    insert(root, target);
}

