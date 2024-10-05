class Solution {
private:
    int dr[4] {1, -1, 0, 0};
    int dc[4] {0, 0, 1, -1};

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(columns, false)); // Fixed
        int closedIslandCount = 0; // Counter for closed islands

        // Traverse each cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) { // Corrected loop
                if (grid[i][j] == 0 && !visited[i][j]) { // Check for land
                    if (dfs(i, j, grid, visited)) { // Call DFS and check if closed
                        closedIslandCount++; // Increment if closed
                    }
                }
            }
        }
        return closedIslandCount; // Return the count of closed islands
    }
    
    // DFS function to explore the island
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // If we are out of bounds, it's not a closed island
        if (!isvalid(r, c, grid)) {
            return false;
        }

        // If the cell is water or already visited, no need to proceed further
        if (grid[r][c] == 1 || visited[r][c]) {
            return true; // Return true for water
        }

        visited[r][c] = true; // Mark this cell as visited
        bool isClosed = true; // Assume it's closed unless proven otherwise

        // Explore all four directions
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            // If any of the neighboring cells lead to out of bounds, mark as not closed
            if (!dfs(nr, nc, grid, visited)) {
                isClosed = false; // Not closed if it touches the border
            }
        }

        return isClosed; // Return whether it's closed
    }

    // Function to check if the cell is within the grid boundaries
    bool isvalid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size(); // Corrected
    }
};
