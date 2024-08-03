#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    vector<int> minSubsequence(vector<int>& nums) {
        //sort
        sort(nums.begin(), nums.end());
        int sumTotal = 0;
        int sumSub = 0;
        int sumCurrent = 0;

        vector<int> ret;

        //calculate total sum
        for (int i = nums.size() - 1; i >= 0; i--) {
            sumTotal += nums[i];
        }

        //compare two sums
        //nums.size() is after the last element 
        for (int i = nums.size() - 1; i >= 0; i--) {
        // for (int i = nums.size(); i >= 0; i--) {
            sumCurrent = sumTotal - sumSub;
            //if sumSub > sumCurrent return ret
            if (sumSub > sumCurrent) {
                break;
            }
            sumSub += nums[i];
            //contain the elements into ret vector
            ret.push_back(nums[i]);
        }

        return ret;
    }
};

void Test() {
    Solution * s = new Solution();
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(4);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    vector<int> ret = s->minSubsequence(arr);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }

    cout << "\n";
}
int main(void) {
    Test();

    return 0;
}