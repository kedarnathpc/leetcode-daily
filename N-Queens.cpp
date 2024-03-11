class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
                vector<int> &leftRow, vector<int> &upperD, vector<int> &lowerD, int n){
        
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; ++row){
            if(leftRow[row] == 0 and lowerD[row - col + n - 1] == 0 and upperD[row + col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerD[row - col + n - 1] = 1;
                upperD[row + col] = 1;
                solve(col + 1, board, ans, leftRow, upperD, lowerD, n);
                leftRow[row] = 0;
                lowerD[row - col + n - 1] = 0;
                upperD[row + col] = 0;
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string temp(n, '.');
        for(int i = 0; i < n; ++i)
            board[i] = temp;

        vector<int> leftRow(n, 0), upperD(2*n-1, 0), lowerD(2*n-1, 0);

        solve(0, board, ans, leftRow, upperD, lowerD, n);

        return ans;
    }
};
