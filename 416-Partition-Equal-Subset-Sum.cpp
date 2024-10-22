class Solution {
    vector<vector<int>> dp;
    vector<int> arr;

    bool can(int idx, int sum) {
        int all = accumulate(arr.begin(), arr.end(), 0);
        int half = all / 2;

        // Boundary check to avoid out-of-bounds access
        if (sum > half) return false;

        // If we reach the end of the array, check if we've hit the half sum
        if (idx == arr.size()) {
            return sum == half;
        }

        int &ret = dp[idx][sum];

        if (ret != -1) {
            return ret;
        }

        // Try leaving or taking the current item
        bool leave = can(idx + 1, sum);
        bool take = can(idx + 1, sum + arr[idx]);

        return ret = (leave || take);
    }

public:
    bool canPartition(vector<int>& nums) {
        arr = nums;
        int all = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, it's impossible to partition into two equal sums
        if (all % 2 != 0) {
            return false;
        }

        int half = all / 2;
        dp.resize(arr.size(), vector<int>(half + 1, -1));

        return can(0, 0);
    }
};
