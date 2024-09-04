// https://leetcode.com/problems/out-of-boundary-paths/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * It seems we are counting number of paths on grid that go out the grid boundry
 * But we go in the 4 directions and trivially cycle (infinite)
 * \t\tdp(r, c)
 *
 * True, but the problem also asks us to do max moves
 * \t\tSo we must add that to the state
 * \t\tdp(r, c, steps)
 * \t\tNow, even we can return to the same (r, c)
 * \t\twe will always have less steps
 *
 * Now code is direct, with careful handling for overflows for C++
 *
 */

const int MOD = 1000000007;

const int MAX = 50 + 1;
int memory[MAX][MAX][MAX];
int rows, cols, max_moves;

int cntWays(int r, int c, int move) {
\tif (move > max_moves)
\t\treturn 0;

\tif (r < 0 || r >= rows || c < 0 || c >= cols)
\t\treturn 1;

\tauto &ret = memory[r][c][move];
\tif (ret != -1)
\t\treturn ret;

\t// We can also use directional array
\tret = cntWays(r, c - 1, move + 1);

\tret += cntWays(r, c + 1, move + 1);
\tret %= MOD;\t// apply after each step

\tret += cntWays(r + 1, c, move + 1);
\tret %= MOD;

\tret += cntWays(r - 1, c, move + 1);
\tret %= MOD;

\treturn ret;
}

class Solution {
public:
\tint findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
\t\trows = m, cols = n, max_moves = maxMove;
\t\tmemset(memory, -1, sizeof(memory));
\t\treturn cntWays(startRow, startColumn, 0);
\t}
};
