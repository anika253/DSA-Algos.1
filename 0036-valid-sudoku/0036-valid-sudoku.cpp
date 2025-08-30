class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate the entire board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    board[i][j] = '.';  // Temporarily empty the cell to avoid self-check
                    if (!isValid(board, i, j, c)) {
                        return false;  // If invalid, return false immediately
                    }
                    board[i][j] = c;  // Restore the original value
                }
            }
        }
        return true;  // If all checks pass, the board is valid
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check if the character 'c' is valid in the given row, column, and sub-grid
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c || board[row][i] == c || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;  // If 'c' is found in the row, column, or 3x3 grid, return false
            }
        }
        return true;  // Otherwise, the cell is valid
    }
};