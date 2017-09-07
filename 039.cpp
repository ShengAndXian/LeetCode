class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end(), less<int>());

            vector<vector<int> > res;
            vector<int> v;

            combinate(res, candidates, target, 0, 0, v);

            return res;
        }

        void combinate(vector<vector<int> >& res, vector<int>& candidates, int target, int pre, int index, vector<int> v) {
            if (index >= candidates.size() || candidates[index] > target)
                return;

            int maxDuplicates = target / candidates[index];

            for (int i = maxDuplicates;i >= 0;i--) {
                int current = pre + candidates[index] * i;
                vector<int> v1 = v;

                for (int j = 0;j < i;j++) 
                    v1.push_back(candidates[index]);

                if (current < target)
                    combinate(res, candidates, target, current, index + 1, v1);
                else if (current == target)
                    res.push_back(v1);
            }
        }
};