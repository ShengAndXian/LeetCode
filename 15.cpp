class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        sort(nums.begin() , nums.end());
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1 , k = nums.size() - 1;
            int target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] > target) {
                    --k;
                }
                else if (nums[j] + nums[k] < target) {
                    ++j;
                }
                else {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);
                    while (j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
                    while (k - 1 >= 0 && nums[k - 1] == nums[k]) --k;
                    ++j;
                    --k;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
            ++i;
        }
        return res;
};
};