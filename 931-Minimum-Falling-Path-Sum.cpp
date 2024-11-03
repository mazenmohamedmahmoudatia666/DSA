class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        // Create a DP table initialized with the values of the first row
        vector<vector<int>> dp = matrix;

        // Fill the DP table from the second row to the last row
        for (int r = 1; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                int minAbove = dp[r - 1][c];  // path directly above
                
                if (c > 0) {
                    minAbove = min(minAbove, dp[r - 1][c - 1]);  // path from the left diagonal
                }
                if (c < columns - 1) {
                    minAbove = min(minAbove, dp[r - 1][c + 1]);  // path from the right diagonal
                }
                
                // Update dp[r][c] with the minimum path sum to reach cell (r, c)
                dp[r][c] = matrix[r][c] + minAbove;
            }
        }

        // Find the minimum path sum in the last row
        return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
    }
};
