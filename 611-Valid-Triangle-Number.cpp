#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Sort the numbers first to ensure that we can easily check the triangle inequality
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check the triangle inequality
                    if (nums[i] + nums[j] > nums[k] && 
                        nums[i] + nums[k] > nums[j] && 
                        nums[j] + nums[k] > nums[i]) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
