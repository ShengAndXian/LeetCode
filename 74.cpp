class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty())
                return false;

            int m = matrix.size();
            int n = matrix[0].size();

            int start = 0;
            int end = m - 1;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (target < matrix[mid][0]) {
                    end = mid - 1;
                } else if (target > matrix[mid][n - 1]) {
                    start = mid + 1;
                } else {
                    int start1 = 0;
                    int end1 = n - 1;

                    while (start1 <= end1) {
                        int mid1 = (start1 + end1) / 2;

                        if (target < matrix[mid][mid1]) 
                            end1 = mid1 - 1;
                        else if (target > matrix[mid][mid1])
                            start1 = mid1 + 1;
                        else 
                            return true;
                    }

                    return false;
                }
            }

            return false;
        }
};