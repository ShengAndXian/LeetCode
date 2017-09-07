class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int> > res(n);

            for (int i = 0;i < n;i++)   
                res[i].resize(n);
            
            int num = 1;
            int x = 0;
            int y = 0;

            while (n > 0) {
                int row = x;
                int col = y;

                while (col < y + n) {
                    res[row][col] = num;
                    col++;
                    num++;
                }

                row++;
                col--;

                while (row < x + n) {
                    res[row][col] = num;
                    row++;
                    num++;
                }

                row--;
                col--;

                while (col >= y) {
                    if (n > 1) {
                        res[row][col] = num;
                        num++;
                    }

                    col--;
                }

                row--;
                col++;

                while (row > x) {
                    if (n > 1) {
                        res[row][col] = num;
                        num++;
                    }

                    row--;
                }

                x++;
                y++;
                n -= 2;
            }

            return res;
        }
};