class Solution {
    vector<vector<string>> res;         // Store all valid board configurations
    vector<string> board;               // Current state of the board
    int n;                              // Board size (n x n)

    bool isValid(int row, int col) {
        // Check if placing a queen at (row, col) is valid
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false; // Same column
            if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false; // Top-left diagonal
            if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false; // Top-right diagonal
        }
        return true;
    }

    void backtracking(int row) {
        if (row == n) {                // Base case: All rows are filled with queens
            res.push_back(board);      // Add the current board configuration to the result
            return;
        }

        for (int col = 0; col < n; ++col) { // Try placing a queen in every column of the current row
            if (isValid(row, col)) {
                board[row][col] = 'Q';  // Place the queen
                backtracking(row + 1); // Recur to the next row
                board[row][col] = '.'; // Backtrack by removing the queen
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;                      // Initialize board size
        board = vector<string>(n, string(n, '.')); // Initialize the board with empty cells
        backtracking(0);                  // Start backtracking from the first row
        return res;                       // Return all valid solutions
    }
};
