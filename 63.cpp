class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > record;

        for (int i = 0;i < m;i++) {
            vector<int> v(n, -1);

            record.push_back(v);
        }

        return uniquePaths(obstacleGrid, m, n, 0, 0, record);
    }

    int uniquePaths(vector<vector<int> >& obstacleGrid, int m, int n, int row, int col, vector<vector<int> >& record) {
        if (obstacleGrid[row][col] == 1)
            return 0;

        if (row == m - 1 && col == n - 1)
            return 1;
        
        int t1 = row + 1 >= m ? 0 : record[row + 1][col];
        int t2 = col + 1 >= n ? 0 : record[row][col + 1];

        if (row + 1 < m && record[row + 1][col] == -1)
            t1 = uniquePaths(obstacleGrid, m, n, row + 1, col, record);
        
        if (col + 1 < n && record[row][col + 1] == -1)
            t2 = uniquePaths(obstacleGrid, m, n, row, col + 1, record);
        
        return record[row][col] = t1 + t2;
    }
};