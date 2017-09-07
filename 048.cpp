class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            rotate1(matrix, 0, 0, matrix.size());
        }

        void rotate1(vector<vector<int> >& matrix, int leftUpx, int leftUpy, int n) {
            if (n <= 0)
                return;
                
            int rightUpx = leftUpx;
            int rightUpy = leftUpy + n - 1;
            int leftDownx = leftUpx + n - 1;
            int leftDowny = leftUpy;
            int rightDownx = leftUpx + n - 1;
            int rightDowny = leftUpy + n - 1;

            for (int i = 0;i < n - 1;i++) {
                int t1 = matrix[rightUpx + i][rightUpy];

                matrix[rightUpx + i][rightUpy] = matrix[leftUpx][leftUpy + i];

                int t2 = matrix[rightDownx][rightDowny - i];

                matrix[rightDownx][rightDowny - i] = t1;

                t1 = matrix[leftDownx - i][leftDowny];

                matrix[leftDownx - i][leftDowny] = t2;

                matrix[leftUpx][leftUpy + i] = t1;
            }

            rotate1(matrix, leftUpx + 1, leftUpy + 1, n - 2);
        }
};