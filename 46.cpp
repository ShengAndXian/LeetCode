class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int> > res;
            vector<int> v;
            vector<int> use(nums.size(), 0);

            permute1(res, nums, 0, use, v);

            return res;
        }

        void permute1(vector<vector<int> >& res, vector<int>& nums, int position, vector<int> use, vector<int> v) {
            if (position >= nums.size()) {
                res.push_back(v);
                return;
            }
            
            for (int i = 0;i < nums.size();i++) {
                if (use[i] == 0) {
                    use[i] = 1;
                    v.push_back(nums[i]);

                    permute1(res, nums, position + 1, use, v);

                    use[i] = 0;
                    v.erase(v.end() - 1);
                 }
            }
        }
};