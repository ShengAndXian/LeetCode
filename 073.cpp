class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<int> v1(m, 1);
            vector<int> v2(n, 1);

            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (matrix[i][j] == 0) {
                        v1[i] = 0;
                        v2[j] = 0;
                    }
                }
            }

            for (int i = 0;i < m;i++) {
                if (v1[i] == 0) {
                    for (int j = 0;j < n;j++) {
                        matrix[i][j] = 0;
                    }
                }
            }

            for (int i = 0;i < n;i++) {
                if (v2[i] == 0) {
                    for (int j = 0;j < m;j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
        }
};