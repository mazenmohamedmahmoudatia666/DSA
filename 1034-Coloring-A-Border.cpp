class Solution {
private:
    int dr[4] {1, -1, 0, 0};
    int dc[4] {0, 0, -1, 1};

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Perform DFS from the starting cell
        dfs(grid, row, col, visited, grid[row][col]);

        // Change the color for border cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] && isBorder(i, j, grid, visited)) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int oldcolor) {
        visited[r][c] = true;

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (isvalid(nr, nc, grid) && !visited[nr][nc] && grid[nr][nc] == oldcolor) {
                dfs(grid, nr, nc, visited, oldcolor);
            }
        }
    }

    bool isvalid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && r < (int)grid.size() && c >= 0 && c < (int)grid[0].size();
    }

    bool isBorder(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // Check if the cell is on the border of the connected component
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (!isvalid(nr, nc, grid) || !visited[nr][nc]) {
                return true;
            }
        }
        return false;
    }
};
