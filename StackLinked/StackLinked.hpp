#include <iostream>
#include <cstdlib>

typedef int DataType;
using namespace std;

typedef struct Node {
    DataType A;
    struct Node * Next;
}Node;

class StackLinked {
private:
    Node * Top;
public:    
    void Push(DataType X);
    void Pop();
    DataType GetTop();
    void MakeEmpty();

    Node * BuyNode(DataType X);
    void Init();
    bool IsEmpty();
};