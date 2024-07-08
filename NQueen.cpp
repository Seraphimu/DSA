#include <iostream>
#include <cstdlib>
#define N 20
using namespace std;

class Queen {
public:
    int Q[N];
    int Count = 0;
    
    void DisSolution(int n);
    bool Place(int i, int j);
    void NQueen(int i, int n);

};

void Queen::DisSolution(int n) {
    printf("第%d个解: ", ++Count);
    for (int i = 1; i <= n; i++) {
        printf("(%d,%d) ", i, Q[i]);
    }
    cout << endl;
}

//(i, j)表示当前第i个皇后的坐标
//测试(1, i - 1)个皇后与第i个皇后的兼容问题，若不兼容在主调函数中j++更换一个列再次尝试
bool Queen::Place(int i, int j) {
    //第一行的皇后直接放置，无条件，皇后的行由递归函数NQueen()控制
    if (i == 1) {
        return true;
    }
    else {
        int k = 1;

        //第k行的纵坐标 == 当前要放置的纵坐标，则在同一个列上，不被允许
        //i - k表示第k个皇后与第i个皇后的横坐标相减，
        //j - Q[k]为第k个皇后的坐标与第i个皇后的纵坐标相减
        //若结果的绝对值相等，则构成等腰直角三角形，在同一对角线上
        //k(1, i - 1)
        while (k < i) {
            if (Q[k] == j || abs(i - k) == abs(j - Q[k])) {
                return false;
            }
            k++;
        }
        //循环完成之后说明找到合适的位置了，返回true
        return true;
    }
}

void Queen::NQueen(int i, int n) {
    if (i > n) {
        //第n个皇后放置完毕
        DisSolution(n);
    }
    else {
        //遍历第i行的第1, n列
        for (int j = 1; j <= n; j++) {
            //如果位置合适，赋值
            if (Place(i, j)) {
                Q[i] = j;
                //且进行下一个皇后（第i+1个）的安放工作
                //若在第i+1行未找到合适的位置，
                //函数会返回到第i行更换在第i行的位置，再进行第i+1行的尝试
                //若未果（j > n，也就是把第i行的所有列都测试完了，还是没有找到合适放皇后的位置）再次返回上一层
                //直到求得结果为止
                NQueen(i + 1, n);
            }
        }
    }
}

void Test() {
    Queen q;
    q.NQueen(1, 6);
}

int main(void)  {
    Test();

    return 0;
}