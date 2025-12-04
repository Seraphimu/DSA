#include <iostream>
#include <cstdlib>

using namespace std;

//对a, b进行归并操作
void merge(int a[], int b[]) {
    uint sizeA = sizeof(a) / a[0];
    uint sizeB = sizeof(b) / b[0];

    int * m = (int *)malloc(sizeof((sizeA + sizeB) * sizeof(int)));

    int i = 0;
    int j = 0;
    int k = 0;
    int t = 0;

    while (i < sizeA && j < sizeB) {
        if (a[i] < b[j]) {
            t = a[i];
            i++;
        }
        else {
            t = b[j];
            j++;
        }

        m[k] = t;
    }

    free(m);
}

void test() {
    //给出两个有序数组a, b
    int a[] = {12, 14, 25, 69, 78};
    int b[] = {16, 36, 48, 52};

    merge(a, b);

}

int main(void) {
    test();

    return 0;
}