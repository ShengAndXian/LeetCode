#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size();) {
            if (nums[i] != nums[nums[i] - 1]) {
                int t;
                t = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = t;
            }
            else {
                ++i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i] - 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums(4,1);
    s.findDuplicates(nums);
}