#include <iostream>
typedef int DataType;
using namespace std;

class Sort {
    public:
    //Sort Methods
    void BubbleSort(DataType A[], int N);
    void SelectionSort(DataType A[], int N);

    // 快速排序
    void QucklySort(DataType A[], int N);
    void QSort(DataType A[], int Low, int High);
    int Partition(DataType A[], int Low, int High);
    
    void MergeSort(DataType A[], int N);
    
    //辅助方法
    void Swap(int & a, int & b);
    void Print(DataType A[], int N);
};


void Sort::BubbleSort(DataType A[], int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        //遍历未排序区
        for (j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                Swap(A[j], A[j + 1]);
            }
        }
    }
}

void Sort::SelectionSort(DataType A[], int N) {
    int i, j;
    int MinIndex;
    //遍历0到N
    for (i = 0; i < N; i++) {
        //遍历i + 1到N，并找出下标i+1到N中的最小值
        MinIndex = i;
        for (j = i + 1; j < N; j++) {
            if (A[MinIndex] > A[j]) {
                MinIndex = j;
            }
        }
        //把最小值交换到剩余序列的首位
        Swap(A[MinIndex], A[i]);
    }
}

int Sort::Partition(DataType A[], int Low, int High) {
    // 选取第一个元素为枢轴
    int PivotKey = A[Low];
    while (Low < High) {
        // 从右向左扫描，找到第一个比枢轴元素小的
        // 本步操作是跳过那些比枢轴元素大的元素
        while (Low < High && A[High] >= PivotKey) {
            High--;
        }
        // 交换，此时枢轴元素是A[High]
        Swap(A[Low], A[High]);

        // 从左向右扫描，找到第一个比枢轴元素大的
        // 本步操作的作用是跳过那些比枢轴元素小的元素
        while (Low < High && A[Low] <= PivotKey) {
            Low++;
        }
        // 交换，此时枢轴元素是A[Low]
        Swap(A[Low], A[High]);
    }

    // 返回枢轴元素所在的位置
    // 此时返回Low和High都行，因为破坏循环的条件是Low == High
    return High;
}

void Sort::QSort(DataType A[], int Low, int High) {
    // 做为枢轴使用
    int Pivot;
    // 若不满足该条件，就意味着一趟排序结束
    if (Low < High) {
        Pivot = Partition(A, Low, High);

        // 对左子表进行排序
        QSort(A, Low, Pivot - 1);
        // 对右子表进行排序
        QSort(A, Pivot + 1, High);
    }

}

void Sort::QucklySort(DataType A[], int N) {
    Sort::QSort(A, 0, N - 1);
}

void Sort::Swap(int & a, int & b) {
    int Tmp = a;
    a = b;
    b = Tmp;
}

void Sort::Print(DataType A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Test() {
    int A[] = {15, -6, 115, 1, 0, 11, -33};
    int SizeA = sizeof (A) / sizeof (A[0]);
    Sort sort;
    //排序前
    sort.Print(A, SizeA);
    //排序算法
    // sort.SelectionSort(A, SizeA);
    // sort.BubbleSort(A, SizeA);
    sort.QucklySort(A, SizeA);
    // 使用方法必须要用到对象
    // Sort::QSort(A, SizeA);
    //排序后
    sort.Print(A, SizeA);
}


int main(void) {
    Test();

    return 0;
}