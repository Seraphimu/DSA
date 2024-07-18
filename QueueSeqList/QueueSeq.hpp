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