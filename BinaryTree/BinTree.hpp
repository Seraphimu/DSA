#include <iostream>
#include <queue>
#include <stack>

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
    void preOrderTraverseIter(Node * root);
    //中序遍历
    void inOrderTraverse(const Node * root);
    //后序遍历
    void postOrderTraverse(const Node * root);
    //层序遍历
    void levelOrderTraverse(const Node * root);
    //置空
    void MakeEmpty(const Node * root);
    //打印叶子节点
    void printLeafNode(const Node * root);
    //求树高
    int treeHeight(const Node * root);
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
    void preOrderTraverseIter();
    //中序遍历
    void inOrderTraverse();
    //后序遍历
    void postOrderTraverse();
    //层序遍历
    void levelOrderTraverse();
    //打印叶子节点
    void printLeafNode();
    //求树高
    void treeHeight();


    //置空
    void MakeEmpty();
}BT;