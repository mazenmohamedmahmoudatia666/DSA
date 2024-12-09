#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> violations;

        // Step 1: Precompute violations
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                violations.push_back(i); // Store the index of the violation
            }
        }

        // Step 2: Process queries using binary search
        vector<bool> result;
        for (const auto& query : queries) {
            int from = query[0], to = query[1] - 1; // Adjust to check pairs only

            // Binary search for the first violation in the range
            auto it = lower_bound(violations.begin(), violations.end(), from);

            // Check if a violation exists in the range
            if (it != violations.end() && *it <= to) {
                result.push_back(false); // Violation found
            } else {
                result.push_back(true); // No violation
            }
        }

        return result;
    }
};
