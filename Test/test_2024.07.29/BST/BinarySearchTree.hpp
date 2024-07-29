#include <iostream>
typedef int DataType;
using namespace std;

//树节点类
class Node {
private:
    //数据域
    DataType data;
    //左右孩子指针域
    Node * left;
    Node * right;
    //允许BinarySearchTree类访问
    friend class BinarySearchTree;
};

//树类
typedef class BinarySearchTree {
private:
    Node * root;
    Node * searchByIter(Node * root, DataType target);
    DataType getMax(Node * root);
    DataType getMin(Node * root);
    Node * insert(Node *& root, DataType target);
    //之前一直写这种形式的，难怪调试半天看见根节点是0，还是吃了这值传递的亏，应该用**或者*&的形式，这样来改变指针
    //这样写和: int a = 114514; int b = a; b = 1919810，这样想通过b改变a的值一样无效。
    // Node * insert(Node * root, DataType target);
    //前序遍历
    void preOrderTraverse(const Node * root);
    //中序遍历
    void inOrderTraverse(const Node * root);
    //后序遍历
    void postOrderTraverse(const Node * root);
public:
    BinarySearchTree() {
        root = nullptr;
    }

    void createManual();
    void searchByIter(DataType target);
    DataType getMax();
    DataType getMin();
    void insert(DataType target);

    //前序遍历
    void preOrderTraverse();
    //中序遍历
    void inOrderTraverse();
    //后序遍历
    void postOrderTraverse();
}BST;