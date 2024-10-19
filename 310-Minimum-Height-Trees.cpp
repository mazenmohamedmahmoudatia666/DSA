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


/*
// https://leetcode.com/problems/minimum-height-trees/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*

We can develop an idea that is inspired from BFS and implemented like a topological sort!

The idea is shrinking (deleting) the tree leaves LEVEL-by-LEVEL
\tUndirected tree node will be leave if in-degree = 1

Imagine a chain: 1-2-3-4-5-6-7
\tNodes 1 and 7 are the current chains. Remove them
\t2-3-4-5-6
\tNext leaves: 2 and 6. Remove (level 2)
\t3-4-5
\tNext leaves: 3 and 5. Remove (level 3)
\t4

\tThis is for odd length

\tFor even length: 1-2-3-4-5-6-7-8
\tStop when there are only 2 nodes: 4-5

The same approach for a tree. The proof is intuitive.
\tLeave nodes will make the tree height very high
\tThe centroids somewhere in the tree are affected by these leaves
\tif a centroid at height 7, after we remove ALL leaves at current level,
\t\tthe this centroid height is decreasing by one

\tSee editorial figures

Implementation:
\tLike topological sort but
\t\tgraph is undirected
\t\tthe focus on in-degree = 1
\t\tStop when there are nodes <= 2

 */
/*
typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to) {
\tgraph[from].push_back(to);
\tgraph[to].push_back(from);
}

vector<int> tree_centroids(const GRAPH &adjList) {\t// O(V)
\tint sz = adjList.size();

\tif(sz == 1)\t\t// special case
\t\treturn {0};

\tvector<int> indegree(sz, 0);
\tfor (int i = 0; i < sz; ++i)
\t\tfor (int j : adjList[i])
\t\t\tindegree[j]++;

\tqueue<int> ready;
\tfor (int i = 0; i < sz; ++i)
\t\tif (indegree[i] == 1)\t// leaves
\t\t\tready.push(i);

\t// keep shrinking leaves: level by level
\twhile (sz > 2) {
\t\tint level_sz = ready.size();\t// how many leaves NOW
\t\tsz -= level_sz;
\t\twhile (level_sz--) {\t// level by level like BFS
\t\t\tint i = ready.front();
\t\t\tready.pop();

\t\t\tfor (int j : adjList[i])
\t\t\t\tif (--indegree[j] == 1)
\t\t\t\t\tready.push(j);
\t\t}
\t}
\tvector<int> res;
\twhile (!ready.empty()) {
\t\tres.push_back(ready.front());
\t\tready.pop();
\t}
\treturn res;
}

class Solution {
public:
\tvector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
\t\tGRAPH graph(edges.size() + 1);

\t\tfor (auto &edge : edges)
\t\t\tadd_undirected_edge(graph, edge[0], edge[1]);

\t\treturn tree_centroids(graph);
\t}
};

int main() {

\treturn 0;
}



*/