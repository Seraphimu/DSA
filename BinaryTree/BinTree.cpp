#include "BinTree.hpp"

Node * BT::buyNode(DataType x) {
    //分配节点
    Node * newNode = new Node();
    //放数据
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

void BT::createManual() {
    // root = buyNode(0);
    // Node * node_1 = buyNode(1);
    // Node * node_2 = buyNode(2);
    // root->left = node_1;
    // root->right = node_2;


    root = buyNode(0);

    Node * node_1 = buyNode(1);
    Node * node_2 = buyNode(2);
    Node * node_3 = buyNode(3);
    Node * node_4 = buyNode(4);
    Node * node_5 = buyNode(5);
    Node * node_6 = buyNode(6);
    Node * node_7 = buyNode(7);
    Node * node_8 = buyNode(8);
    Node * node_9 = buyNode(9);

    root->left = node_1;
    root->right = node_2;

    node_1->left = node_3;
    node_1->right = node_4;

    node_2->left = node_5;
    node_2->right = node_6;

    node_3->left = node_7;

    node_5->left = node_8;
    node_5->right = node_9;
}


void BT::preOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void BT::preOrderTraverse() {
    preOrderTraverse(root);
    cout << "\n";
}

void BT::preOrderTraverseIter(Node * root) {
    Node * cur = root;
    stack<Node *> st;
    //栈不空，或者树不空
    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            cout << cur->data << " ";
            st.push(cur);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
}

void BT::preOrderTraverseIter() {
    cout << "Iter preOrder:\n";
    preOrderTraverseIter(root);
    cout << "\n";
}


void BT::inOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
} 

void BT::inOrderTraverse() {
    inOrderTraverse(root);
    cout << "\n";
}


void BT::postOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " ";
}

void BT::postOrderTraverse() {
    postOrderTraverse(root);
    cout << "\n";
}


void BT::levelOrderTraverse(const Node * root) {
    if (root == nullptr) {
        return;
    }

    //建立一个存放Node*型数据的队列
    queue<const Node *> qn;
    const Node * cur;
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

void BT::levelOrderTraverse() {
    levelOrderTraverse(root);
    cout << "\n";
}


void BT::MakeEmpty(const Node * root) {
    if (root == nullptr) {
        return;
    }

    //建立一个存放Node*型数据的队列
    queue<const Node *> qn;
    const Node * cur;
    //根节点先进队列
    qn.push(root);

    //队列非空时持续循环
    while (!qn.empty()) {
        //获取队头指针
        cur = qn.front();
        //判断是否有子节点，有则入队
        if (cur->left != nullptr) {
            qn.push(cur->left);
        }
        if (cur->right != nullptr) {
            qn.push(cur->right);
        }
        cout << cur->data;
        //释放队头节点的指针
        delete cur;
        cur = nullptr;
        cout << " as been poped!\n";
        //把队头元素出队
        qn.pop();
    }

    cout << "Make Empty Successfully!\n";
}

void BT::MakeEmpty() {
    MakeEmpty(root);
}

void BT::printLeafNode(const Node * root) {
    if (root == nullptr) {
        return;
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ";
        }
        else {
            printLeafNode(root->left);
            printLeafNode(root->right);
        }
    }
}

void BT::printLeafNode() {
    printLeafNode(root);
    cout << "\n";
}

int BT::treeHeight(const Node * root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        
        //返回较大者
        return leftHeight > rightHeight ? leftHeight: rightHeight + 1;
    }
}

void BT::treeHeight() {
    cout << "Tree Height:\n";
    cout << treeHeight(root);
    cout << "\n";
}

