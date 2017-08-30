class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int flag1[10][10] = {0};
            int flag2[10][10] = {0};
            int flag3[10][10] = {0};

            for (int i = 0;i < board.size();i++) {
                for (int j = 0;j < board[i].size();j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '0';
                        int k = i / 3 * 3 + j / 3;

                        if (flag1[i][num] || flag2[j][num] || flag3[k][num])
                            return false;
                        
                        flag1[i][num] = flag2[j][num] = flag3[k][num] = 1;
                    }
                }
            }

            return true;
        }
};