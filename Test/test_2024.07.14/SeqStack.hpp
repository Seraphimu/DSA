#include <iostream>
#include <cstdlib>
#define MAX 6
using namespace std;

typedef int DataType;

class SeqStack {
public:
    DataType * A;
    int Top;

    void Init();
    void Push(DataType X);
    void Pop();
    DataType GetTop();
    void MakeEmpty();

    bool IsEmpty();
    bool IsFull();
};