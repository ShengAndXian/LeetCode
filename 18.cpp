class Solution {
    public:
        vector<vector<int> > fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end(), less<int>());

            vector<vector<int> > res;

            for (int i = 0;i < nums.size();i++) {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                for (int j = i + 1;j < nums.size();j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1])
                        continue;

                    int currentTarget = target - nums[i] - nums[j];

                    int start = j + 1;
                    int end = nums.size() - 1;

                    while (start < end) {
                        int currentSum = nums[start] + nums[end];

                        if (currentSum == currentTarget) {
                            vector<int> v;

                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[start]);
                            v.push_back(nums[end]);

                            res.push_back(v);

                            int t1 = nums[start];
                            int t2 = nums[end];

                            start++;
                            end--;

                            while (start < nums.size() && nums[start] == t1)
                                start++;
                            
                            while (end > j && nums[end] == t2)
                                end--;
                        }
                        else if (currentSum > currentTarget) {
                            end--;
                        }
                        else {
                            start++;
                        }
                    }
                }
            }

            return res;
        }
};