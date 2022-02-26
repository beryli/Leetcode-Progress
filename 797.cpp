class Solution {
public:
    void DFS (vector<vector<int>>& ret, vector<vector<int>>& graph, int cur_node, vector<int>& vec) {
        if (cur_node == graph.size() - 1) {ret.push_back(vec);}
        for (int node : graph[cur_node]) {
            vec.push_back(node);
            DFS(ret, graph, node, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> method_1(vector<vector<int>>& graph) {
        vector<int> root{0};
        vector<vector<int>> ret;
        DFS (ret, graph, 0, root);
        return ret;
    }
    
    vector<vector<int>> DFS_2 (vector<vector<int>>& graph, int cur_node, vector<int> vec) {
        if (cur_node == graph.size() - 1) {return vector<vector<int>>{vec};}
        vector<vector<int>> ret;
        for (int node : graph[cur_node]) {
            vec.push_back(node);
            vector<vector<int>> path = DFS_2(graph, node, vec);
            ret.insert(ret.end(), path.begin(), path.end());
            vec.pop_back();
        }
        return ret;
    }
    vector<vector<int>> method_2(vector<vector<int>>& graph) {
        return DFS_2 (graph, 0, vector<int>{0});
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // return method_1(graph);
        return method_2(graph);
    }
};