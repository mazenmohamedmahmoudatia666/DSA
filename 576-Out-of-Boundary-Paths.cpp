
const int MOD = 1000000007;

const int MAX = 50 + 1;
int memory[MAX][MAX][MAX];
int rows, cols, max_moves;
class Solution {

\tint ans(int r, int c, int move) {
\t\tif (move == -1)
\t\t\treturn 0;

\t\tif (r < 0 || r >= rows || c < 0 || c >= cols)
\t\t\treturn 1;

\t\treturn memory[r][c][move];
\t}
  public:
\tint findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
\t\t// #Moves is the thing that control the state (actual indexing). Must be first loop
\t\trows = m, cols = n, max_moves = maxMove;

\t\tfor (int move = 0; move <= maxMove; ++move) {
\t\t\tfor (int r = 0; r < rows; ++r) {
\t\t\t\tfor (int c = 0; c < cols; ++c) {

\t\t\t\t\tint ret = ans(r, c - 1, move - 1);
\t\t\t\t\tret += ans(r, c + 1, move - 1);
\t\t\t\t\tret %= MOD;
\t\t\t\t\tret += ans(r + 1, c, move - 1);
\t\t\t\t\tret %= MOD;
\t\t\t\t\tret += ans(r - 1, c, move - 1);
\t\t\t\t\tret %= MOD;
\t\t\t\t\tmemory[r][c][move] = ret;
\t\t\t\t}
\t\t\t}
\t\t}
\t\treturn ans(startRow, startColumn, maxMove);
\t}
};