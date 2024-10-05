class Solution {
private:
    int dr[4] = {-1, 1, 0, 0}; // Directions for row movement
    int dc[4] = {0, 0, -1, 1}; // Directions for column movement

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int subIslandCount = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid2[r][c] == 1 && !visited[r][c]) {
                    // Start a DFS to check if this island is a sub-island
                    if (dfs(r, c, grid1, grid2, visited)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }

    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        // Mark the current cell as visited
        visited[r][c] = true;

        // Check if the current cell is part of an island in grid1
        bool isSubIsland = grid1[r][c] == 1;

        // Visit all 4 neighboring cells
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (isValid(nr, nc, grid2) && grid2[nr][nc] == 1 && !visited[nr][nc]) {
                // If any part of the DFS returns false, this island cannot be a sub-island
                if (!dfs(nr, nc, grid1, grid2, visited)) {
                    isSubIsland = false;
                }
            }
        }

        return isSubIsland;
    }

    bool isValid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};
