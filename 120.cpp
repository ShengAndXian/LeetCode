class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            vector<int> v(triangle.size());

            return minimum(triangle, 0, 0, v);
        }

        int minimum(vector<vector<int> >& triangle, int row, int index, vector<int>& v) {
            if (row >= triangle.size())
                return 0;

            int t1 = 0;
            int t2 = 0;
            int t3 = triangle[row][index];

            if (index == 0)
                t1 = minimum(triangle, row + 1, index, v);
            else
                t1 = v[index];

            t2 = minimum(triangle, row + 1, index + 1, v);

            int res = t1 < t2 ? t1 + t3 : t2 + t3;

            v[index] = res;

            return res;
        }
};