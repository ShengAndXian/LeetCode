class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> dp(n);

            for (int i = 0;i < n;i++)
                dp[i] = i == 0 ? grid[0][i] : grid[0][i] + dp[i - 1];
            
            for (int i = 1;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    int t1 = dp[j];
                    int t2 = j == 0 ? 100000 : dp[j - 1];

                    dp[j] = min(t1, t2) + grid[i][j];
                }
            }

            return dp[n - 1];
        }
};