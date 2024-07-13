#include <iostream>
#include <cstdlib>
#define MAX 5

typedef int DataType;
using namespace std;

class StackSeq {
public:
    DataType * A;
    int Top;

    void Push(DataType X);
    void Pop();
    DataType GetTop();
    void MakeEmpty();

    void Init();
    bool IsFull();
    bool IsEmpty();
};

typedef struct Node {
    DataType A;
    struct Node * Next;
}Node;

class StackLinked {
public:
    Node * STHead;
    
    void Push(DataType X);
    void Pop();
    DataType GetTop();
    void MakeEmpty();
    Node * BuyNode(DataType X);

    void Init();
    bool IsEmpty();
};