class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if (board.empty())
                return;

            int m = board.size();
            int n = board[0].size();
            vector<vector<bool> > accessible;

            for (int i = 0;i < m;i++) {
                vector<bool> v1(n, false);
                accessible.push_back(v1);
            }

            for (int i = 0;i < n;i++) {
                if (board[0][i] == 'O') {
                    accessible[0][i] = true;
                    BFS(board, 1, i, accessible);
                }
            }

            for (int i = 0;i < n;i++) {
                if (board[m - 1][i] == 'O') {
                    accessible[m - 1][i] = true;
                    BFS(board, m - 2, i, accessible);
                }
            }

            for (int i = 0;i < m;i++) {
                if (board[i][0] == 'O') {
                    accessible[i][0] = true;
                    BFS(board, i, 1, accessible);
                }
            }

            for (int i = 0;i < m;i++) {
                if (board[i][n - 1] == 'O') {
                    accessible[i][n - 1] = true;
                    BFS(board, i, n - 2, accessible);
                }
            }

            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (board[i][j] == 'O' && !accessible[i][j])
                        board[i][j] = 'X';
                }
            }
        }

        void BFS(vector<vector<char> >& board, int row, int col, vector<vector<bool> >& accessible) {
            int m = board.size();
            int n = board[0].size();

            if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == 'X')
                return;
            
            accessible[row][col] = true;

            queue<pair<int, int> > q;
            pair<int, int> p(row, col);

            q.push(p);

            while (!q.empty()) {
                p = q.front();
                q.pop();
                row = p.first;
                col = p.second;

                if (row - 1 > 0 && board[row - 1][col] == 'O' && !accessible[row - 1][col]) {
                    accessible[row - 1][col] = true;
                    p.first = row - 1;
                    p.second = col;
                    q.push(p);
                }

                if (row + 1 < m - 1 && board[row + 1][col] == 'O' && !accessible[row + 1][col]) {
                    accessible[row + 1][col] = true;
                    p.first = row + 1;
                    p.second = col;
                    q.push(p);
                }

                if (col - 1 > 0 && board[row][col - 1] == 'O' && !accessible[row][col - 1]) {
                    accessible[row][col - 1] = true;
                    p.first = row;
                    p.second = col - 1;
                    q.push(p);
                }

                if (col + 1 < n - 1 && board[row][col + 1] == 'O' && !accessible[row][col + 1]) {
                    accessible[row][col + 1] = true;
                    p.first = row;
                    p.second = col + 1;
                    q.push(p);
                }
            }
        }
};