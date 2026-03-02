class Solution {
public:
    int count = 0;

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2*n - 1, 0);
        vector<int> lowerDiag(2*n - 1, 0);

        solve(0, board, leftRow, upperDiag, lowerDiag, n);

        return count;
    }

    void solve(int col,
               vector<string> &board,
               vector<int> &leftRow,
               vector<int> &upperDiag,
               vector<int> &lowerDiag,
               int n) {

        // base case: valid configuration found
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {

            if (leftRow[row] == 0 &&
                lowerDiag[row + col] == 0 &&
                upperDiag[n - 1 + col - row] == 0) {

                // place queen
                board[row][col] = 'Q';

                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                // recurse
                solve(col + 1, board, leftRow, upperDiag, lowerDiag, n);

                // backtrack
                board[row][col] = '.';

                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }
};