class Solution {
public:
    bool isValid(int i, int len_i, int j, int len_j) {
        return (i < len_i && i >= 0) && (j < len_j && j >= 0);
    }
    
    vector<vector<int>> getNeighbors(int i, int m, int j, int n) {
        vector<vector<int>> ret;
        if (isValid(i+1, m, j, n)) {ret.push_back(vector<int>{i+1, j});}
        if (isValid(i, m, j+1, n)) {ret.push_back(vector<int>{i, j+1});}
        if (isValid(i, m, j-1, n)) {ret.push_back(vector<int>{i, j-1});}
        if (isValid(i-1, m, j, n)) {ret.push_back(vector<int>{i-1, j});}
        return ret;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        vector<vector<int>> neighbors = getNeighbors(i, m, j, n);
        for (vector<int> nei : neighbors) {
            if (!visited[nei[0]][nei[1]] && grid[nei[0]][nei[1]] == '1') {
                dfs (nei[0], nei[1], grid, visited);
            }
        }
        return; 
    }
        
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++ ) {
            for (int j = 0; j < n; j++ ) {
                if (!visited[i][j] && grid[i][j] == '1'){
                    dfs (i, j, grid, visited);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
};