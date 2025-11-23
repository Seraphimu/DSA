#include "BinaryTree.h"

void BinaryTree::create() {
    Node * a = new Node('a');
    Node * b = new Node('b');
    Node * c = new Node('c');
    Node * d = new Node('d');
    Node * e = new Node('e');
    Node * f = new Node('f');
    Node * g = new Node('g');

    this->root = a;

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

}

void BinaryTree::levelOrderTraverse() {
    //创建一个队列, 层序遍历使用
    queue<Node *> q;

    q.push(this->root);
    Node * cur = nullptr;

    while (!q.empty()) {
        //获取队头元素, 并输出
        cur = q.front();
        cout << cur->data << " ";

        //如果存在左右子树, 入队
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }

        //左右子树全部入队后, 队头元素出队, 下一次使用新的队头再做相同的操作
        q.pop();
    }

    cout << "\n";
    
}

void BinaryTree::preOrderTraverseIter() {
    if (this->root == nullptr) return;
    
    stack<Node*> s;
    Node* cur = this->root;
    
    while (cur != nullptr || !s.empty()) {
        // 访问当前节点，并一路向左
        while (cur != nullptr) {
            cout << cur->data << " ";  // 访问节点
            s.push(cur);               // 压栈以便后续访问右子树
            cur = cur->left;
        }
        
        // 转向右子树
        if (!s.empty()) {
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
    cout << "\n";
}

void BinaryTree::inOrderTraverseIter() {
    if (this->root == nullptr) return;
    
    stack<Node*> s;
    Node* cur = this->root;
    
    while (cur != nullptr || !s.empty()) {
        // 访问当前节点，并一路向左
        while (cur != nullptr) {
            s.push(cur);               // 压栈以便后续访问右子树
            cur = cur->left;
        }
        // 转向右子树
        if (!s.empty()) {
            cur = s.top();
            s.pop();
            cout << cur->data << " ";  // 访问节点
            cur = cur->right;
        }

    }
    cout << "\n";
}


//未完全掌握
void BinaryTree::postOrderTraverseIter() {
    if (this->root == nullptr) return;
    
    stack<Node*> s;
    Node* cur = this->root;
    Node* lastVisited = nullptr;  // 记录上次访问的节点
    
    while (cur != nullptr || !s.empty()) {
        // 一路向左到底
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            Node* topNode = s.top();
            
            // 如果右子树存在且未被访问过
            if (topNode->right != nullptr && lastVisited != topNode->right) {
                cur = topNode->right;  // 转向右子树
            } else {
                // 访问当前节点
                cout << topNode->data << " ";
                lastVisited = topNode;
                s.pop();
            }
        }
    }
    cout << "\n";
}

//未完全掌握
void BinaryTree::postOrderTraverseIterTwoStack() {
    if (this->root == nullptr) return;
    
    stack<Node*> s1, s2;
    s1.push(this->root);
    
    while (!s1.empty()) {
        Node* cur = s1.top();
        s1.pop();
        s2.push(cur);  // 将节点压入第二个栈
        
        // 先左后右入栈s1
        if (cur->left != nullptr) {
            s1.push(cur->left);
        }
        if (cur->right != nullptr) {
            s1.push(cur->right);
        }
    }
    
    // s2中的出栈顺序就是后序遍历
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << "\n";
}