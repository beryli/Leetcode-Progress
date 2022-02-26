class Solution {
public:
    void BFS (vector<vector<char>>& board, vector<vector<bool>>& visit, pair<int, int> cell) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> di{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push(cell);
        while(!q.empty()){
            pair<int, int> cur_cell = q.front();
            q.pop();
            for (vector<int> d : di) {
                int row = cur_cell.first + d[0];
                int col = cur_cell.second+ d[1];
                if (row < 0 || row >= m || col < 0 || col >= n) {continue;}
                if (board[row][col] == 'O' && !visit[row][col]) {
                    q.push(make_pair(row, col));
                    visit[row][col] = true;
                }
            }
        }
        
        return;
    }
    
    void method_1 (vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && i < m-1 && j > 0 && j < n-1) {continue;}
                if (board[i][j] == 'O' && !visit[i][j]) {
                    BFS (board, visit, make_pair(i, j));
                }
            }
        }
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (board[i][j] == 'O' && !visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
    
    void DFS (vector<vector<char>>& board, pair<int, int> cell) {
        int m = board.size(), n = board[0].size();
        board[cell.first][cell.second] = '#';
        vector<vector<int>> di{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (vector<int> d : di) {
            int row = cell.first + d[0];
            int col = cell.second+ d[1];
            if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {continue;}
            else {DFS (board, make_pair(row, col));}
        }
        return ;
    }
    
    void method_2 (vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && i < m-1 && j > 0 && j < n-1) {continue;}
                if (board[i][j] == 'O') {
                    DFS (board, make_pair(i, j));
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        // method_1(board);
        method_2(board);
        return;
    }
};