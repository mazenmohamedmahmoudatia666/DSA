class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Initialize distances to a large value
        vector<int> dist(n, 1e8);
        dist[k - 1] = 0; // Convert 1-based index to 0-based

        // Perform Bellman-Ford for (n - 1) iterations
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (const auto& time : times) {
                int u = time[0] - 1; // Convert to 0-based index
                int v = time[1] - 1; // Convert to 0-based index
                int w = time[2];

                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            // If no updates were made, we can terminate early
            if (!updated) break;
        }

        // Find the maximum distance in the dist array
        int maxTime = *max_element(dist.begin(), dist.end());
        return (maxTime == 1e8) ? -1 : maxTime;
    }
};
