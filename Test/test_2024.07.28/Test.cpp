#include <iostream>
#define SIZE 10
using namespace std;
//一个数组，第一个下标留着放哨兵位
int arr[SIZE] = {0, -1, -5, 99, 11, 90, 24, 0, 23, 15};

int searchBySent(int * arr, int target) {
    //把下标0赋值为目标
    arr[0] = target;

    int i;
    for (i = SIZE - 1; i >= 0; i--) {
        if (arr[i] == target) {
            //如果i没有走到头，即1至SIZE-1下标处有target元素的存在，返回下标
            return i;
        }
    }

    //如果是在下标0处找到的，返回-1
    return -1;
}

int main(void) {
    cout << "looking for 114514: " << searchBySent(arr, 114514) << "\n";
    cout << "looking for 11: " << searchBySent(arr, 11) << "\n";

    return 0;
}