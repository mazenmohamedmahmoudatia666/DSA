class Solution {
    int lcs(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: if idx reaches the end of the array, no more subsequence can be formed
        if (idx == nums.size())
            return 0;

        // Use prev_idx + 1 as the index in dp to handle the case when prev_idx == -1
        auto& ret = dp[idx][prev_idx + 1];
        if (ret != -1)
            return ret;

        // Case 1: Don't pick the current element
        int leave = lcs(idx + 1, prev_idx, nums, dp);

        // Case 2: Pick the current element (if it's greater than the previous one)
        int pick = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            pick = 1 + lcs(idx + 1, idx, nums, dp);
        }

        // Store the result in the dp table and return the maximum of both options
        ret = max(leave, pick);
        return ret;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] will store the LIS length starting from index `i` with `j-1` as the previous index
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // n+1 to handle prev_idx == -1 case

        // Start the recursion with idx = 0 and prev_idx = -1 (no previous element yet)
        return lcs(0, -1, nums, dp);
    }
};
