class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int start = 0;

            while (true) {
                int max = -1;
                int index = 0;

                for (int i = start + 1;i < nums.size() && i <= start + nums[start];i++) {
                    if (i - start + nums[i] > max) {
                        max = i - start + nums[i];
                        index = i;
                    }
                }

                if (index == nums.size() - 1)
                    return true;
                
                if (nums[index] == 0)
                    return false;
                
                start = index;
            }
        }
};