#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Step 2: Initialize distance and ways arrays
        vector<long long> dist(n, LLONG_MAX); // Distance to each node
        vector<int> ways(n, 0);              // Number of ways to reach each node
        dist[0] = 0;
        ways[0] = 1;

        // Step 3: Use a priority queue for Dijkstra's Algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0); // (distance, node)

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist > dist[u]) continue; // Skip stale entries

            // Step 4: Relax edges
            for (auto& [v, w] : graph[u]) {
                long long newDist = currentDist + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u]; // Update ways to v
                    pq.emplace(newDist, v);
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // Add new ways
                }
            }
        }

        // Step 5: Return the number of ways to reach node n-1
        return ways[n-1];
    }
};
