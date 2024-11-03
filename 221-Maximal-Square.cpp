class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        int maxSize = 0;

        // Iterate through each cell in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    // If we're at the first row or first column
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // The largest square is 1x1
                    } else {
                        // Calculate the size of the square at (i, j)
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSize = max(maxSize, dp[i][j]); // Update max size
                }
            }
        }
        return maxSize * maxSize; // Return the area of the largest square
    }
};

// Example Usage:
