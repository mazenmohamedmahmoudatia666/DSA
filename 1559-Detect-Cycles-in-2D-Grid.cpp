#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int dr[4] {1, -1, 0, 0}; // Row directions
    int dc[4] {0, 0, 1, -1}; // Column directions

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(columns, false)); // Track visited cells

        // Loop through each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                // Start DFS if the cell is not visited
                if (!visited[i][j]) {
                    if (dfs(i, j, grid, visited, i, j)) { // Use -1 for previous coordinates
                        return true; // If a cycle is detected
                    }
                }
            }
        }
        return false; // No cycle found
    }

    bool dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, int prevR = -1, int prevC = -1) {
        // Check if out of bounds or already visited
        if (!isvalid(r, c, grid) || visited[r][c]) {
            return false;
        }

        // Mark the current cell as visited
        visited[r][c] = true;

        // Explore all four directions
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d]; // New row
            int nc = c + dc[d]; // New column

            // Continue DFS if it's not the previous cell
            if (isvalid(nr, nc, grid) && (nr != prevR || nc != prevC)) {
                // Check if the adjacent cell is the same character and not visited
                if (grid[nr][nc] == grid[r][c]) {
                    if (visited[nr][nc] || dfs(nr, nc, grid, visited, r, c)) {
                        return true; // Cycle detected
                    }
                }
            }
        }

        return false; // No cycle found from this path
    }

    bool isvalid(int r, int c, vector<vector<char>>& grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size(); // Check bounds
    }
};
