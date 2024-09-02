#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    const int MAX = 101 + 1;
    int memory[101][101];
    vector<vector<int>> grid;

    int cntWays(int r, int c) {
        int rows = grid.size(), cols = grid[0].size();

        // Bounds check and obstacle check
        if (r >= rows || c >= cols || grid[r][c] == 1)
            return 0;  // invalid cell or obstacle

        // Handle cases where start or end cell is an obstacle
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
            return 0;  // No valid path if start or end is blocked
        // Base case: if we have reached the target cell
        if (r == rows - 1 && c == cols - 1)
            return 1;

        // Memoization check
        auto &ret = memory[r][c];
        if (ret != -1)
            return ret;

        // Recursive calls to check right and down cells
        return ret = cntWays(r + 1, c) + cntWays(r, c + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        

        // Initialize memory with -1 for memoization
        memset(memory, -1, sizeof(memory));
        
        // Start the recursion from the top-left corner
        return cntWays(0, 0);
    }
};

