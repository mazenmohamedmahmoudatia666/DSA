class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1); // DP array to store the minimum cost
        
        dp[0] = 0; // Starting point
        dp[1] = 0; // You can start at step 0 or step 1 without any cost

        // Fill the dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        return dp[n]; // Minimum cost to reach the top
    }
};
