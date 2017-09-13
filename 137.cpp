class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int a = 0;
            int b = 0;

            for (int i = 0;i < nums.size();i++) {
                int t = (a & ~b & ~nums[i]) | (~a & b & nums[i]);
                b = (~a & b & ~nums[i]) | (~a & ~b & nums[i]);
                a = t;
            }

            return a | b;
        }
};