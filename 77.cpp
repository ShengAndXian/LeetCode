class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int> > res;
            vector<int> v;

            combine1(res, v, n, k, 0);

            return res;
        }

        void combine1(vector<vector<int> >& res, vector<int> v, int n, int k, int num) {
            if (k == 0) {
                res.push_back(v);
                return;
            }

            for (int i = num + 1;i <= n - k + 1;i++) {
                v.push_back(i);

                combine1(res, v, n, k - 1, i);

                v.pop_back();
            }
        }
};