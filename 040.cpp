class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());

        vector<int> newCandidates;
        vector<int> duplicates;

        for (int i = 0;i < candidates.size();) {
            newCandidates.push_back(candidates[i]);

            int t = candidates[i];
            int times = 0;

            while (i < candidates.size() && candidates[i] == t) {
                times++;
                i++;
            }

            duplicates.push_back(times);
        }

        vector<vector<int> > res;
        vector<int> v;

        combinate(res, newCandidates, duplicates, target, 0, 0, v);

        return res;
    }

    void combinate(vector<vector<int> >& res, vector<int>& newCandidates, vector<int>& duplicates, int target, int pre, int index, vector<int> v) {
        if (index >= newCandidates.size() || newCandidates[index] > target) 
            return;

        for (int i = duplicates[index];i >= 0;i--) {
            int current = pre + newCandidates[index] * i;
            vector<int> v1 = v;

            for (int j = 0;j < i;j++)
                v1.push_back(newCandidates[index]);
            
            if (current < target)
                combinate(res, newCandidates, duplicates, target, current, index + 1, v1);
            else if (current == target)
                res.push_back(v1);
        }
    }
};