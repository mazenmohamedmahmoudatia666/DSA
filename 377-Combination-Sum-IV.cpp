#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return process(target, nums);
    }

private:
    vector<int> dp;

    int process(int target, vector<int>& nums) {
        if (target == 0) return 1;  // Base case: one valid way if target is exactly zero
        if (target < 0) return 0;   // No valid way if target becomes negative

        auto& ret = dp[target];
        if (ret != -1) return ret;

        ret = 0;
        for (int coin : nums) {
            ret += process(target - coin, nums);  // Recursive call
        }

        return ret;
    }
};

