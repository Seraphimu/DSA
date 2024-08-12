#include <iostream>
#include <vector>
//using accumulate() method
#include <numeric>
#include <algorithm>

using namespace std;

int pivotIndex(vector<int> & nums) {
    //sum of left
    int left = 0;
    //sum of right
    int right = 0;
    //sum of nums;
    //从0开始累加从[nums.begin(), nums.end()]的元素
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    //遍历nums，一边遍历一边计算左、右的和
    for (int i = 0; i < nums.size() - 1; i++) {
        //当下标在0时，left为0，右侧值为sum - left - nums[i]
        if (i == 0) {
            left = 0;
            right = sum - left - nums[i];
            //若左右之和相等，则返回i
            if (left == right) {
                return i;
            }
        }
        //当i的下标不为0时，左侧的和为nums[0] + nums[1] + ... + nums[i - 1]
        //右侧为sum - left - nums[i]
        else {
            left += nums[i - 1];
            right = sum - left - nums[i];
            if (left == right) {
                return i;
            }
        }
    }

    //遍历完整个数组还没有找到合适的下标，则返回-1
    return -1;
}

void test() {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(6);
    cout << pivotIndex(nums) << "\n";
}

int main(void) {

    test();

    return 0;
}
