class Solution {
private:
    // Helper function to add directed edges to the graph
    void add_directed_graph(vector<vector<int>>& graph, int from, int to) {
        graph[from].push_back(to);
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // Create adjacency lists for red and blue edges
        vector<vector<int>> graphRed(n), graphBlue(n);
        for (const auto& edge : redEdges) {
            add_directed_graph(graphRed, edge[0], edge[1]);
        }
        for (const auto& edge : blueEdges) {
            add_directed_graph(graphBlue, edge[0], edge[1]);
        }

        // Initialize distance array with -1 and visited arrays
        vector<int> distance(n, -1); // Stores the shortest distance
        vector<vector<bool>> visited(n, vector<bool>(2, false)); // Tracks visited with red and blue edges
        
        // Start from node 0, distance 0
        distance[0] = 0;

        // Queue for BFS: {node, edge color}, where color 0 is red and color 1 is blue
        queue<pair<int, int>> q;
        q.push({0, 0}); // Start with a red edge from node 0
        q.push({0, 1}); // Start with a blue edge from node 0

        int level = 0;  // Distance level
        while (!q.empty()) {
            int size = q.size();
            level++; // Increase distance with each level of BFS

            for (int i = 0; i < size; i++) {
                auto [node, color] = q.front();
                q.pop();

                if (visited[node][color]) {
                    continue; // Skip if the node has been visited with the same edge color
                }

                visited[node][color] = true;

                // Explore neighbors using the opposite color
                if (color == 0) {  // Current color is red, explore blue edges
                    for (int neighbor : graphBlue[node]) {
                        if (!visited[neighbor][1]) { // Blue edges from this node
                            q.push({neighbor, 1});
                            if (distance[neighbor] == -1) {
                                distance[neighbor] = level;  // Set the distance
                            }
                        }
                    }
                } else {  // Current color is blue, explore red edges
                    for (int neighbor : graphRed[node]) {
                        if (!visited[neighbor][0]) { // Red edges from this node
                            q.push({neighbor, 0});
                            if (distance[neighbor] == -1) {
                                distance[neighbor] = level;  // Set the distance
                            }
                        }
                    }
                }
            }
        }

        return distance;
    }
};
