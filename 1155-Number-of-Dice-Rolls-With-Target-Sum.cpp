class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int t = 1; t <= target; t++) {
                for (int face = 1; face <= k; face++) {
                    if (t >= face) {
                        dp[dice][t] = (dp[dice][t] + dp[dice - 1][t - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};
