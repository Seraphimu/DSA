#include <iostream>
#include <queue>

using namespace std;

typedef int DataType;

class Node {
private:
    DataType data;
    Node * left;
    Node * right;
    friend class BinaryTree;
};

typedef class BinaryTree {
private:
    Node * root;
    //前序遍历
    void preOrderTraverse(const Node * root);
    //中序遍历
    void inOrderTraverse(const Node * root);
    //后序遍历
    void postOrderTraverse(const Node * root);
    //层序遍历
    void levelOrderTraverse(const Node * root);
    //置空
    void MakeEmpty(const Node * root);
public:
    //初始化
    BinaryTree() {
       root = nullptr;
    }
    //分配节点
    Node * buyNode(DataType x);
    //手动构建
    void createManual();
    //前序遍历
    void preOrderTraverse();
    //中序遍历
    void inOrderTraverse();
    //后序遍历
    void postOrderTraverse();
    //层序遍历
    void levelOrderTraverse();

    //置空
    void MakeEmpty();
}BT;