#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the type for the graph as an adjacency list
typedef vector<vector<int>> GRAPH;

// Function to add an undirected edge to the graph
void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

// Depth-First Search (DFS) to explore connected components
void dfs(GRAPH &graph, int node, vector<bool> &visited, vector<int> &cc_nodes) {
    visited[node] = true; // Mark the current node as visited
    cc_nodes.push_back(node); // Add the current node to the connected component

    // Explore all neighbors of the current node
    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) // If the neighbor hasn't been visited
            dfs(graph, neighbour, visited, cc_nodes); // Recursively visit it
    }
}

class Solution {
public:
    // Main function to find the smallest string with swaps
    string smallestStringWithSwaps(string str, vector<vector<int>> &pairs) {
        int nodes = str.size(); // Get the number of nodes (length of the string)
        GRAPH graph(nodes); // Initialize the graph

        // Build graph edges from the pairs
        for (int i = 0; i < (int)pairs.size(); ++i) {
            add_undirected_edge(graph, pairs[i][0], pairs[i][1]);
        }

        vector<bool> visited(nodes); // Visited array to track visited nodes

        // Loop through all nodes to find connected components
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) { // If the node hasn't been visited
                vector<int> cc_nodes; // To hold indices of the connected component
                dfs(graph, i, visited, cc_nodes); // Perform DFS

                // Get the characters corresponding to the connected component
                string cc_letters;
                for (int node : cc_nodes)
                    cc_letters += str[node];

                // Sort the indices and the letters
                sort(cc_nodes.begin(), cc_nodes.end());
                sort(cc_letters.begin(), cc_letters.end());

                // Assign the sorted letters back to the original string
                for (int j = 0; j < (int)cc_nodes.size(); j++)
                    str[cc_nodes[j]] = cc_letters[j];
            }
        }
        return str; // Return the final result
    }
};

