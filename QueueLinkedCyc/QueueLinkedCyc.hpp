#include <iostream>
#include <cstdlib>
#define MAX 6

typedef int DataType;
using namespace std;

typedef struct Node {
    DataType A;
    struct Node * Next;
}Node;

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