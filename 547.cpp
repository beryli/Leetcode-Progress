class Solution {
public:
    void bfs(int root, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(root);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            for (int i = 0; i < isConnected.size(); i++){
                if (isConnected[node][i] && !visited[i])
                    {q.push(i);}
            }
        }
        return;
    }
    
    void dfs(int root, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[root] = true;
        for (int i = 0; i < isConnected.size(); i++){
            if (isConnected[root][i] && !visited[i]) {
                dfs (i, isConnected, visited);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int groups = 0;
        for (int i = 0; i < isConnected.size(); i++){
            if (!visited[i]){
                // bfs(i, isConnected, visited);
                dfs(i, isConnected, visited);
                groups++;
            }
        }
        return groups;
    }
};