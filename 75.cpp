class Solution {
    public:
        void sortColors(vector<int>& nums) {
            quickSort(nums, 0, nums.size() - 1);
        }

        void quickSort(vector<int>& nums, int start, int end) {
            if (start >= end)
                return;

            int p1 = start;
            int p2 = end - 1;
            int target = nums[end];

            while (p1 <= p2) {
                while (p1 < end && nums[p1] <= target)
                    p1++;
                
                while (p2 >= start && nums[p2] > target)
                    p2--;
                
                if (p1 < p2)
                    swap(nums, p1, p2);
                else
                    swap(nums, p1, end);
            }

            quickSort(nums, 0, p1 - 1);
            quickSort(nums, p1 + 1, end);
        }

        void swap(vector<int>& nums, int p1, int p2) {
            int t = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = t;
        }
};