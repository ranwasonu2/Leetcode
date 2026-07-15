class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    void solve(vector<vector<int>>& board, int row, int n) {
        if (row == n) {
            vector<string> temp;

            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                }
                temp.push_back(s);
            }

            ans.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;
                solve(board, row + 1, n);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(board, 0, n);
        return ans;
    }
};