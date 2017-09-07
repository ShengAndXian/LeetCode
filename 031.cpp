class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int index = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                index = i;
                break;
            }
        }
        if (index == 0) {
            Invert(nums , 0 , nums.size() - 1);
        }
        else {
            int j = nums.size() - 1;
            while (j >= index) {
                if (nums[j] > nums[index - 1])
                    break;
                j--;
            }
            Swap(nums , j , index - 1);
            Invert(nums , index , nums.size() - 1);
        }
    }
    void Swap(vector<int> &nums , int start , int end) {
        int t = nums[start];
        nums[start] = nums[end];
        nums[end] = t;
    }
    void Invert(vector<int> &nums , int start , int end) {
        while (start < end) {
            Swap(nums , start , end);
            start++;
            end--;
        }
    }
};