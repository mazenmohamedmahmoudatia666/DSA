class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum is odd, it's not possible to partition it into two equal subsets
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // A sum of 0 is always achievable

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
