class Solution {
    vector<vector<int>> res;
    vector<int> prem;
    vector<bool> visited;

    void bt(vector<int>& nums) {
        if (prem.size() == nums.size()) {
            res.push_back(prem);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip if the number has already been used or if it's a duplicate of the previous number.
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }

            visited[i] = true;
            prem.push_back(nums[i]);
            bt(nums);

            visited[i] = false;
            prem.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        visited = vector<bool>(nums.size(), false);
        bt(nums);
        return res;
    }
};
