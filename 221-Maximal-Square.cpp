class Solution {
public:
    vector<vector<int>> dp;

    // Recursive function to find the maximum size of square
    int maxSquareSize(vector<vector<char>>& matrix, int r, int c) {
        // Boundary conditions
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] == '0') {
            return 0;
        }

        // Memoization check
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        // Recursively find the size of the square ending at (r, c)
        dp[r][c] = 1 + min({maxSquareSize(matrix, r - 1, c),    // top
                            maxSquareSize(matrix, r, c - 1),    // left
                            maxSquareSize(matrix, r - 1, c - 1)}); // diagonal

        return dp[r][c];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int columns = matrix[0].size();
        dp.resize(rows, vector<int>(columns, -1));
        int maxSize = 0;

        // Check each cell to find the largest square
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    maxSize = max(maxSize, maxSquareSize(matrix, i, j));
                }
            }
        }
        
        return maxSize * maxSize; // Return the area of the largest square
    }
};

