class Solution {
public:
    bool search(int i, int row, int col, int m, int n, string word, vector<vector<char>> &board){
        if(i == word.size())
            return true;

        if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[i] || board[row][col] == '!')
            return false;

        char c = board[row][col];
        board[row][col] = '!';

        bool up = search(i+1, row-1, col, m, n, word, board);
        bool down = search(i+1, row+1, col, m, n, word, board);
        bool left = search(i+1, row, col-1, m, n, word, board);
        bool right = search(i+1, row, col+1, m, n, word, board);

        board[row][col] = c;
        
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    if(search(0, i, j, m, n, word, board))
                        return true;
                }
            }
        }

        return false;
    }
};
