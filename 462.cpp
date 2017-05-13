#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<long long> sum;
        sum.push_back(nums[0]);
        for (int i = 1;i < nums.size();i++) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
        long long res;
        int flag = 1;
        for (int i = 0;i < nums.size();i++) {
            long long tmp1 = nums[i] * i;
            if (i > 0)
                tmp1 = tmp1 - sum[i - 1];
            long long tmp2 = nums[i] * (nums.size() - i - 1);
            tmp2 = sum[nums.size() - 1] - sum[i] - tmp2;
            if (tmp1 < 0 || tmp2 < 0)
                continue;
            if (flag) {
                flag = 0;
                res = tmp1 + tmp2;
            }
            else if(tmp1 + tmp2 < res)
                res = tmp1 + tmp2;
        }
        return res;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(203125577);
    nums.push_back(-349566234);
    nums.push_back(230332704);
    nums.push_back(48321315);
    nums.push_back(66379082);
    nums.push_back(386516853);
    nums.push_back(50986744);
    nums.push_back(-250908656);
    nums.push_back(-425653504);
    nums.push_back(-212123143);
    Solution s;
    cout << s.minMoves2(nums) << endl;
}