#include <iostream>
#include <cstdlib>
#define MAX 6
using namespace std;

typedef int DataType;
class DoubleStack {
private:
    DataType *A;
    //两个栈的栈顶
    int TP;
    int TB;
public:
    //建立一个空栈
    void Init();
    //判空、判满
    bool IsEmpty();
    bool IsFull();
    //入栈，根据Top的值入栈
    void Push(DataType X, int Top);
    //出栈，根据Top的值出栈
    void Pop(int Top);
    //摧毁栈
    void MakeEmpty();
    //获取栈顶元素，根据栈顶的值
    DataType GetTopValue(int Top);

    //获取两个栈顶的指针
    int GetTP();
    int GetTB();
};