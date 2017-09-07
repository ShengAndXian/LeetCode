class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int pre = -1;
            int count = 1;

            for (int i = 0;i < nums.size();i++) {
                if (nums[i] == pre) {
                    count++;

                    if (count > 2) {
                        nums.erase(nums.begin() + i);
                        i--;
                    }
                } else {
                    pre = nums[i];
                    count = 1;
                }
            }

            return nums.size();
        }
};