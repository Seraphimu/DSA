#include <iostream>
#define MAX 114
typedef int DataType;
using namespace std;

class MaxSubSum {
    public:
        DataType MaxSubSumForce_1(DataType A[], int N) {
            DataType ThisSum;
            DataType MaxSum = 0;
            int i, j, k;
            //控制左端
            for (i = 0; i < N; i++) {
                //控制右端
                for (j = i; j < N; j++) {
                    ThisSum = 0;
                    //逐个测试i到j之间的子列和
                    for (k = i; k <= j; k++) {
                        ThisSum += A[k];
                    }
                    if (ThisSum > MaxSum) {
                        MaxSum = ThisSum;
                    }
                }
            }
            return MaxSum;
        }

        DataType MaxSubSumForce_2(DataType A[], int N) {
            DataType ThisSum;
            DataType MaxSum = 0;
            int i, j;
            //控制左端
            for (i = 0; i < N; i++) {
                ThisSum = 0;
                //控制右端
                for (j = i; j < N; j++) {
                    //逐个测试i到j之间的子列和
                    ThisSum += A[j];
                    if (ThisSum > MaxSum) {
                        MaxSum = ThisSum;
                    }
                }
            }
            return MaxSum;
        }

        //状态转移方程
        //dp[0] = A[0];
        //dp[i] = max{dp[i - 1] + A[i], A[i]}
        DataType dp[MAX] = {0};
        DataType MaxSubSumDP(DataType A[], int N) {
            dp[0] = A[0];
            int MaxIndex = 0;
            int i;
            //求dp数组
            for (i = 1; i < N; i++) {
                //若dp[i - 1] + A[i] < A[i]，则可判断dp[i - 1] < 0
                dp[i] = max(dp[i - 1] + A[i], A[i]);
            }

            for (i = 0; i < N; i++) {
                if (A[MaxIndex] < A[i]) {
                    MaxIndex = i;
                }
            }

            return dp[MaxIndex];
        }

        DataType MaxSubSumOL(DataType A[], int N) {
            int ThisSum = 0;
            int MaxSum = 0;
            int i;
            
            for (i = 0; i < N; i++) {
                ThisSum += A[i];

                //一直加，如果连续子序列和为一个负数，直接放弃该结果，该结果只会让后面的结果变小
                if (ThisSum < 0) {
                    ThisSum = 0;
                }
                if (ThisSum > MaxSum) {
                    MaxSum = ThisSum;
                }
            }

            return MaxSum;
        }
};


void Test() {
    DataType A[] = {4, -1, 2, 3, -2, 5, -6, 9};
    int SizeA = sizeof (A) / sizeof(A[0]);
    MaxSubSum ms;
    cout << ms.MaxSubSumForce_1(A, SizeA) << endl;
    cout << ms.MaxSubSumForce_2(A, SizeA) << endl;
    cout << ms.MaxSubSumOL(A, SizeA) << endl;
    cout << ms.MaxSubSumDP(A, SizeA) << endl;
}

int main(void) {
    Test();

    return 0;
}