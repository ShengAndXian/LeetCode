class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end(), less<int>());

            vector<int> newNums;
            vector<int> count;

            for (int i = 0;i < nums.size();) {
                newNums.push_back(nums[i]);

                int tmp = nums[i];
                int times = 0;  
                
                while (i < nums.size() && nums[i] == tmp) {
                    i++;
                    times++;
                }

                count.push_back(times);
            }

            vector<vector<int> > res;
            vector<int> v;

            subset(newNums, count, res, v, 0);

            return res;
        }

        void subset(vector<int>& nums, vector<int>& count, vector<vector<int> >& res, vector<int> v, int index) {
            if (index >= nums.size()) {
                res.push_back(v);
                return;
            }

            for (int i = 0;i <= count[index];i++) {
                vector<int> v1(v);

                for (int j = 0;j < i;j++)
                    v1.push_back(nums[index]);
                
                subset(nums, count, res, v1, index + 1);
            }
        }
};