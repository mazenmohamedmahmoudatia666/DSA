#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    vector<int> dp;  // To store minimum costs
    vector<int> pays; // To store costs

    int cost(int idx) {
        if (idx >= pays.size())
            return 0;

        auto& ret = dp[idx];
        if (ret != -1)
            return ret;

        ret = INT_MAX;
        ret = min(ret, pays[idx] + cost(idx + 1)); // Current step cost
        ret = min(ret, pays[idx] + cost(idx + 2)); // Skipping one step

        return ret; // Return the computed minimum cost
    }

public:
    int minCostClimbingStairs(vector<int>& costs) { // Renamed parameter to avoid conflict
        dp.resize(costs.size(), -1); // Resize the dp vector
        pays = costs; // Store costs

        return min(cost(0), cost(1)); // Call the cost function correctly
    }
};
