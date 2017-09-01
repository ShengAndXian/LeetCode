class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end(), less<int>());

            vector<vector<int> > res;
            vector<int> v;
            vector<int> use(nums.size(), 0);

            permuteUnique1(res, nums, use, 0, v);

            return res;
        }

        void permuteUnique1(vector<vector<int> >& res, vector<int>& nums, vector<int> use, int position, vector<int> v) {
            if (position >= nums.size()) {
                res.push_back(v);
                return;
            }

            for (int i = 0;i < nums.size();i++) {
                if (i > 0 && nums[i] == nums[i - 1] && use[i - 1] == 0)
                    continue;
                
                if (use[i] == 0) {
                    use[i] = 1;
                    v.push_back(nums[i]);

                    permuteUnique1(res, nums, use, position + 1, v);

                    use[i] = 0;
                    v.erase(v.end() - 1);
                }
            }
        }
};