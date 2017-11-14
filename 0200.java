class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0)
            return 0;

        int res = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] flag = new int[m][n];

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                flag[i][j] = 0;
            }
        }

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1' && flag[i][j] == 0) {
                    res++;
                    DFS(grid, flag, i, j);
                }
            }
        }

        return res;
    }

    void DFS(char[][] grid, int[][] flag, int x, int y) {
        flag[x][y] = 1;

        if (y != 0 && grid[x][y - 1] == '1' && flag[x][y - 1] == 0)
            DFS(grid, flag, x, y - 1);
        if (x != grid.length - 1 && grid[x + 1][y] == '1' && flag[x + 1][y] == 0)
            DFS(grid, flag, x + 1, y);
        if (y != grid[0].length - 1 && grid[x][y + 1] == '1' && flag[x][y + 1] == 0)
            DFS(grid, flag, x, y + 1);
        if (x != 0 && grid[x - 1][y] == '1' && flag[x - 1][y] == 0)
            DFS(grid, flag, x - 1, y);
    }
}