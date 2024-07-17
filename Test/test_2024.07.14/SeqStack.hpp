#include <iostream>
#include <cstdlib>
#define MAX 6
using namespace std;

typedef int DataType;

class SeqStack {
public:
    //数组
    DataType * A;
    //栈顶
    int Top;

    //建立一个空栈
    void Init();
    //把X入栈
    void Push(DataType X);
    //出栈
    void Pop();
    //获取栈顶元素
    DataType GetTop();
    //摧毁栈
    void MakeEmpty();

    //判空，判满
    bool IsEmpty();
    bool IsFull();
};