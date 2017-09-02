class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            int m = matrix.size();
            int n = matrix.empty() ? 0 : matrix[0].size();
            int x = 0;
            int y = 0;

            while (m > 0 && n > 0) {
                int cx = x;
                int cy = y;

                while (cy <= y + n - 1) {
                    res.push_back(matrix[cx][cy]);
                    cy++;
                }

                cx++;
                cy--;

                while (cx <= x + m - 1) {
                    res.push_back(matrix[cx][cy]);
                    cx++;
                }

                cx--;
                cy--;

                while (cy >= y) {
                    if (m > 1)
                        res.push_back(matrix[cx][cy]);
                    cy--;
                }

                cx--;
                cy++;

                while (cx > x) {
                    if (n > 1)
                        res.push_back(matrix[cx][cy]);
                    cx--;
                }

                x++;
                y++;
                m -= 2;
                n -= 2;
            }

            return res;
        }
};