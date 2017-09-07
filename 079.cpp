class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();

            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (board[i][j] == word[0]) {
                        if (exist1(board, word, 0, i, j))
                            return true;
                    }
                }
            }

            return false;
        }

        bool exist1(vector<vector<char> >& board, string word, int index, int row, int col) {
            int m = board.size();
            int n = board[0].size();

            if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index])
                return false;

            if (index >= word.length() - 1)
                return true;

            char c = board[row][col];
            board[row][col] = '.';

            if (exist1(board, word, index + 1, row - 1, col) || exist1(board, word, index + 1, row + 1, col) || exist1(board, word, index + 1, row, col - 1) || exist1(board, word, index + 1, row, col + 1))
                return true;
                
            board[row][col] = c;

            return false;
        }
};