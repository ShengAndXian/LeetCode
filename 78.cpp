class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int> > res;
            vector<int> v;

            subsets1(nums, res, v, 0);

            return res;
        }

        void subsets1(vector<int>& nums, vector<vector<int> >& res, vector<int> v, int index) {
            if (index >= nums.size()) {
                res.push_back(v);
                return;
            }

            subsets1(nums, res, v, index + 1);

            v.push_back(nums[index]);
            subsets1(nums, res, v, index + 1);
        }
};