class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        
        // Iterate over the largest side of the triangle (nums[k])
        for (int k = 2; k < n; ++k) {
            int l = 0, r = k - 1; // Use two pointers to find valid (i, j) pairs
            while (l < r) {
                if (nums[l] + nums[r] > nums[k]) {
                    // If nums[l] + nums[r] > nums[k], all pairs (l, l+1, ..., r-1) are valid
                    cnt += (r - l);  // Count all valid pairs
                    r--;  // Move the right pointer to the left
                } else {
                    l++;  // Move the left pointer to the right
                }
            }
        }
        
        return cnt;
    }
};
