#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// int min_num(vector<int> nums_1, vector<int> nums_2) {
//     vector<int> arr;

//     int i = 0, j = 0;
//     //合并两个数组到第三个数组中
//     while (i < nums_1.size() && j < nums_2.size()) {
//         if (nums_1[i] <= nums_2[j]) {
//             arr.push_back(nums_1[i]);
//             i++;
//         }
//         else {
//             arr.push_back(nums_2[j]);
//             j++;
//         }
//     }

//     //处理剩余部分
//     //nums_1剩余部分
//     if (i < nums_1.size()) {
//         int k = i;
//         while (k < nums_1.size()) {
//             arr.push_back(nums_1[k]);
//             k++;
//         }
//     }
//     //nums_2剩余部分
//     else {
//         int k = j;
//         while (k < nums_2.size()) {
//             arr.push_back(nums_2[k]);
//             k++;
//         }
//     }

//     cout << "arr: ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";

//     //第几个下标要减一
//     //返回第5个，其下标为4
//     return arr[arr.size() / 2 - 1];
// }

int min_num(vector<int> nums_1, vector<int> nums_2) {
    int size = nums_1.size() + nums_2.size();
    int ret = size / 2 - 1;
    int cnt = 0;

    int i = 0, j = 0;
    while (i < nums_1.size() && j < nums_2.size()) {
        if (nums_1[i] <= nums_2[j]) {
            if (cnt == ret) {
                return nums_1[i];
            }
            i++;
        }
        else {
            if (cnt == ret) {
                return nums_2[j];
            }
            j++;
        }
        cnt++;
    }

    //无
    return -1;
}

void test() {
    vector<int> nums_1;
    vector<int> nums_2;
    nums_1.push_back(11);
    nums_1.push_back(13);
    nums_1.push_back(15);
    nums_1.push_back(17);


    nums_2.push_back(2);
    nums_2.push_back(4);
    nums_2.push_back(6);
    nums_2.push_back(8);

    cout << min_num(nums_1, nums_2);
    cout << "\n";
}

int main(void) {
    test();

    return 0;
}