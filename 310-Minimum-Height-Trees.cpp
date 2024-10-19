class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // If there's only one node, it's the only root.

        // Step 1: Build the graph (adjacency list) and calculate the degree of each node
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0); // Track the degree (number of edges) of each node.

        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Initialize the queue with all leaf nodes (nodes with degree 1)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Step 3: Perform BFS and trim the leaves layer by layer
        int remainingNodes = n;
        while (remainingNodes > 2) { // We stop when we have 1 or 2 nodes left
            int leafCount = q.size();
            remainingNodes -= leafCount; // Remove all current leaf nodes
            
            for (int i = 0; i < leafCount; i++) {
                int leaf = q.front();
                q.pop();

                // For each leaf node, reduce the degree of its neighbor
                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor); // Add new leaf nodes to the queue
                    }
                }
            }
        }

        // Step 4: The remaining nodes in the queue are the roots of the minimum height trees
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
