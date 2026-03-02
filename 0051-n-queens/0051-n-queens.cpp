class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0, board ,n);
        return ans;
    }
    void solve(int col, vector<string> &board, int n) {
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1, board ,n);
                board[row][col] = '.';
            }
        }
    }
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int r = row;
        int c = col;
        // 1. check left side row
        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }
        // 2. check upper-left diagonal
        r = row;
        c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        // 3. check lower-left diagonal
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }
};