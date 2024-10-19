class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    // Check if a cell is within bounds
    bool is_valid(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    // DFS function to find the longest increasing path
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c] != -1) return dp[r][c];  // If already computed
        
        int maxLength = 1;  // The cell itself counts as a path of length 1
        
        // Explore all four directions
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (is_valid(grid, nr, nc) && grid[nr][nc] > grid[r][c]) {
                maxLength = max(maxLength, 1 + dfs(grid, dp, nr, nc));
            }
        }

        return dp[r][c] = maxLength;  // Store the result in dp
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        // DP table to memoize results, initialized to -1
        vector<vector<int>> dp(rows, vector<int>(columns, -1));
        
        int longestPath = 0;
        
        // Apply DFS to every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                longestPath = max(longestPath, dfs(matrix, dp, i, j));
            }
        }
        
        return longestPath;
    }
};