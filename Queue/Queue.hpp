#include <iostream>
#include <cstdlib>
#define MAX 6

typedef int DataType;
using namespace std;

class QueueSeq {
//我*******
public:
    DataType * A;
    int Front;
    int Rear;

    //PushFront
    void Push(DataType X);
    void Pop();
    DataType GetFront();
    DataType GetRear();
    void MakeEmpty();

    void Init();
    bool IsFull();
    bool IsEmpty();
};

typedef struct Node {
    DataType A;
    struct Node * Next;
}Node;

class QueueLinked {
public:
    Node * Front;
    Node * Rear;
public:
    void Push(DataType X);
    void Pop();
    DataType GetFront();
    DataType GetRear();
    void MakeEmpty();

    Node * BuyNode(DataType X);
    void Init();
    bool IsEmpty();
};

class QueueCycLinked {
private:
    Node * Front;
    Node * Rear;
public:
    void Push(DataType X);
    void Pop();
    DataType GetFront();
    DataType GetRear();
    void MakeEmpty();

    Node * BuyNode(DataType X);
    void Init();
    bool IsEmpty();
};