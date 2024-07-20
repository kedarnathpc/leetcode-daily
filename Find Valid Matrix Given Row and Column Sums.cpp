class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int ROW = rowSum.size(), COL = colSum.size();
        vector<vector<int>> result (ROW, vector<int> (COL, 0));

        int i = 0, j = 0;

        while (i < ROW && j < COL) {

            result[i][j] = min (rowSum[i], colSum[j]);
            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];

            rowSum[i] == 0 ? i++ : j++;
        }

        return result;
    }
};
