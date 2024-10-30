class Solution {
    int dp[1001][3000]; // Update size for larger targets
    const int MOD = 1000000007;
    int dices, faces;

    int cntways(int idx, int target) {
        if (target < 0) return 0; // invalid
        if (idx == dices && target == 0) return 1; // all dices done and target achieved
        if (idx == dices || target == 0) return 0; // still more to finish

        auto &ret = dp[idx][target];
        if (ret != -1) return ret;
        ret = 0;

        // Loop from 1 to faces (inclusive)
        for (int i = 1; i <= faces; i++) {
            ret += cntways(idx + 1, target - i); // Correct the index here
            ret %= MOD; // early reduce the range
        }

        return ret;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dices = n;
        faces = k;
        memset(dp, -1, sizeof(dp)); // Initialize dp array
        return cntways(0, target);
    }
};
