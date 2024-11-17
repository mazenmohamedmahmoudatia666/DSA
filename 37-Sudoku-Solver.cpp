class Solution {
    unordered_map<int, unordered_set<char>> row;
    unordered_map<int, unordered_set<char>> col;
    unordered_map<int, unordered_set<char>> square;

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;  // Solved all rows
        if (c == 9) return backtrack(board, r + 1, 0);  // Move to the next row
        if (board[r][c] != '.') return backtrack(board, r, c + 1);  // Skip filled cells

        int square_index = (r / 3) * 3 + c / 3;

        for (char num = '1'; num <= '9'; ++num) {
            if (row[r].count(num) || col[c].count(num) || square[square_index].count(num))
                continue;  // Skip if num is already used

            // Place the number
            board[r][c] = num;
            row[r].insert(num);
            col[c].insert(num);
            square[square_index].insert(num);

            if (backtrack(board, r, c + 1)) return true;  // Recur to the next cell

            // Undo placement
            board[r][c] = '.';
            row[r].erase(num);
            col[c].erase(num);
            square[square_index].erase(num);
        }

        return false;  // No valid number found
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize the state
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char cell = board[i][j];
                if (cell != '.') {
                    row[i].insert(cell);
                    col[j].insert(cell);
                    square[(i / 3) * 3 + j / 3].insert(cell);
                }
            }
        }

        backtrack(board, 0, 0);
    }
};
