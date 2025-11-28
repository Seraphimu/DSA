#include <iostream>

using namespace std;

void Swap(int * A, int * B)
{
    int Tmp = *A;
    *A = *B;
    *B = Tmp;
}

int Paration(int Array[], int Low, int High)
{
    //选取第一个元素为枢轴
    int PivotKey = Array[Low];

    //
    while (Low < High)
    {
        //先从右向左扫描，发现比Pivot小的就放到Low的位置上（初始时Low的值保存在PivotKey中，可以直接被覆盖）
        //（当High指向的数据拷贝到Low指向的空间时，原先High的值亦可被覆盖）
        while (Low < High && Array[High] > PivotKey)
        {
            High--;
        }

        Swap(&Array[High], &Array[Low]);

        while (Low < High && Array[Low] < PivotKey)
        {
            Low++;
        }

        Swap(&Array[High], &Array[Low]);
    }
    
    return Low;
}

void QSort(int Array[], int Low, int High)
{
    int Pivot;

    if (Low < High)
    {
        Pivot = Paration(Array, Low, High);
        QSort(Array, Low, Pivot);
        QSort(Array, Pivot + 1, High);
    }
}


int main(void)
{
	int Array[] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	int High = sizeof(Array) / sizeof(int) - 1;
	QSort(Array, 1, High);

    return 0;
}
