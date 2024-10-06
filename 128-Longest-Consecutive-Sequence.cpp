typedef unordered_map<int, vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to) {
\tgraph[from].push_back(to);
    graph[to].push_back(from);
}

// The graph is chain: 1->2->3->4. We return the chain size
int dfs(GRAPH &graph, int node, unordered_set<int> &visited) {
\tvisited.insert(node);

\tfor (int neighbour : graph[node])
\t\tif (!visited.count(neighbour))
\t\t\treturn 1 + dfs(graph, neighbour, visited);
\treturn 1;\t// single last node
}

class Solution {
public:
\tint longestConsecutive(vector<int> &nums) {
\t\t// Create hashset of the values to lookup in O(1)
\t\tunordered_set<int> nums_set(nums.begin(), nums.end());

        if(nums_set.size() == 0)
            return 0; // handle empty graph

        // Create undirected edges. If val and val+1 exists, we have an edge
        GRAPH graph;
\t\tfor (int val : nums_set) {\t// ITERATE on unique values
\t\t\tif (nums_set.count(val + 1))
\t\t\t\tadd_undirected_edge(graph, val, val + 1);
\t\t}

\t\t// Find the CCs. Maximize over the CC size
\t\tint mx_cc_size = 1;  // value 1 = handle graph of separate values  [10, 20, 30]
\t\tunordered_set<int> visited;

\t\tfor (auto &node_adj : graph) {
\t\t\tif (!visited.count(node_adj.first) && node_adj.second.size() == 1) {
\t\t\t\tint cc_size = dfs(graph, node_adj.first, visited);
\t\t\t\tmx_cc_size = max(mx_cc_size, cc_size);
\t\t\t}
\t\t}
\t\treturn mx_cc_size;
\t}
};  