
class Solution {
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& DAG, vector<bool>& visited, int node) {
        visited[node] = true;
        path.push_back(node);

        if (node == DAG.size() - 1) {  // If reached the last node
            res.push_back(path);
        } else {
            for (auto& neighbor : DAG[node]) {
                if (!visited[neighbor]) {
                    dfs(DAG, visited, neighbor);
                }
            }
        }

        path.pop_back();  // Backtrack
        visited[node] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        dfs(graph, visited, 0);  // Start from node 0
        return res;
    }
};
