#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Initialize the memory with -1 (to be used in memoization)
        vector<vector<int>> memory(coins.size() + 1, vector<int>(amount + 1, -1));
        return count_coins_change(0, amount, coins, memory);
    }

private:
    int count_coins_change(int idx, int target, vector<int>& coins, vector<vector<int>>& memory) {
        if (target < 0)
            return 0;

        if (target == 0)
            return 1; // Found a valid way to make the target amount

        if (idx == coins.size())
            return 0; // No more coins to consider

        // Use memoization to avoid re-computation
        int &ret = memory[idx][target];
        if (ret != -1)
            return ret;

        // Case 1: Skip the current coin
        int leave = count_coins_change(idx + 1, target, coins, memory);

        // Case 2: Take the current coin (stay at the same index, subtract coin value from target)
        int take = count_coins_change(idx, target - coins[idx], coins, memory);

        // Memoize and return the result
        return ret = leave + take;
    }
};