class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end(), less<int>());

            int sum;
            int lose = 10000000;

            for (int i = 0;i < nums.size();i++) {
                int start = 0;
                int end = nums.size() - 1;

                int currentTarget = target - nums[i];

                while (true) {
                    if (start == i)
                        start++;
                    
                    if (end == i)
                        end--;
                    
                    if (start >= end)
                        break;
                    
                    int currentSum = nums[start] + nums[end];
                    int currentLose = abs(currentTarget - currentSum);

                    if (currentLose < lose) {
                        lose = currentLose;
                        sum = nums[i] + currentSum;
                    }

                    if (currentSum > currentTarget)
                        end--;
                    else if (currentSum < currentTarget)
                        start++;
                    else
                        return sum;
                }
            }

            return sum;
        }
};