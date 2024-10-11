class Solution {
    int dr[4]{1, -1, 0, 0};
    int dc[4]{0, 0, 1, -1};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        vector<vector<bool>> visited_pacific(rows, vector<bool>(columns, false));
        vector<vector<bool>> visited_atlantic(rows, vector<bool>(columns, false));
        queue<pair<int, int>> q_pacific, q_atlantic;

        // Add all Pacific-bordering cells to q_pacific
        for (int i = 0; i < rows; ++i) {
            q_pacific.push({i, 0});
            visited_pacific[i][0] = true;
        }
        for (int j = 0; j < columns; ++j) {
            q_pacific.push({0, j});
            visited_pacific[0][j] = true;
        }

        // Add all Atlantic-bordering cells to q_atlantic
        for (int i = 0; i < rows; ++i) {
            q_atlantic.push({i, columns - 1});
            visited_atlantic[i][columns - 1] = true;
        }
        for (int j = 0; j < columns; ++j) {
            q_atlantic.push({rows - 1, j});
            visited_atlantic[rows - 1][j] = true;
        }

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < columns && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };

        // Run BFS for Pacific and Atlantic
        bfs(q_pacific, visited_pacific);
        bfs(q_atlantic, visited_atlantic);

        // Collect cells that can flow to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (visited_pacific[i][j] && visited_atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
