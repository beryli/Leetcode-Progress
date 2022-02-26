class Solution {
public:
    vector<pair<int, int>> getNeighbors (pair<int, int> cell, int n) {
        vector<pair<int, int>> ret;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <=1; j++) {
                if (i == 0 && j == 0) {continue;}
                else {
                    if (cell.first + i >= 0 && cell.first + i < n && cell.second + j >= 0 && cell.second + j < n)
                    {ret.push_back(make_pair(cell.first + i, cell.second + j));}
                }
            }
        }
        return ret;
    }
    
    void BFS (vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& len, pair<int, int> cell){
        int n = grid.size();
        
        queue<pair<int, int>> q;
        q.push(pair<int, int>(cell.first, cell.second));
        while (!q.empty()) {
            pair<int, int> cur_cell = q.front();
            q.pop();
            vector<pair<int, int>> neigh = getNeighbors(cur_cell, n);
            for(pair<int, int> nei : neigh) {
                if (!visited[nei.first][nei.second] && grid[nei.first][nei.second] == 0) {
                    visited[nei.first][nei.second] = true;
                    q.push(pair<int, int>(nei.first, nei.second));
                    len[nei.first][nei.second] = len[cur_cell.first][cur_cell.second] + 1;
                }
            }
        }
        return;
    }
    
    int method_1 (vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n-1][n-1] == 1 || grid[0][0]) {return -1;}
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        vector<vector<int>> len(n, vector<int>(n, -1));
        len[n-1][n-1] = 1;
        BFS(grid, visited, len, make_pair(n-1, n-1));
        return len[0][0];
    }
    
    int method_2 (vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n-1][n-1] == 1 || grid[0][0]) {return -1;}
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        /* BFS */
        int ans = 0, num_cells;
        queue<pair<int, int>> q;
        q.push(make_pair(n-1, n-1));
        visited[n-1][n-1] = true;
        while (!q.empty()) {
            ans++;
            num_cells = q.size();
            for (int i = 0; i < num_cells; i++) {
                pair<int, int> cur_cell = q.front();
                q.pop();
                if (cur_cell.first == 0 && cur_cell.second == 0) {return ans;}
                vector<pair<int, int>> neigh = getNeighbors(cur_cell, n);
                for(pair<int, int> nei : neigh) {
                    if (!visited[nei.first][nei.second] && grid[nei.first][nei.second] == 0) {
                        visited[nei.first][nei.second] = true;
                        q.push(pair<int, int>(nei.first, nei.second));
                    }
                }
            }
        }
        
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // return method_1(grid);
        return method_2(grid);
    }
};