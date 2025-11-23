#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef char T;


struct Node {
    //节点元素
    T data;
    //左右子树
    class Node * left;
    class Node * right;

    /**
     * 构造函数，传入参数x则可以创建一个树的节点
     */
    Node(T x) {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }

    
};

class BinaryTree {
private:
    Node * root;
public:
    void create();
    void levelOrderTraverse();
    void preOrderTraverseIter();
    void inOrderTraverseIter();
    void postOrderTraverseIter();
    void postOrderTraverseIterTwoStack();

};