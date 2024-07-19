class Solution {
public:
    bool isMinimum (int number, int row, vector<vector<int>> &matrix) {
        return number == *min_element(matrix[row].begin(), matrix[row].end());
    }

    bool isMaximum (int number, int col, vector<vector<int>> &matrix) {
        int maxi = INT_MIN;

        for (int i = 0; i < matrix.size(); ++i) {
            maxi = max(maxi, matrix[i][col]);
        }

        return maxi == number;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isMinimum(matrix[i][j], i, matrix) && isMaximum(matrix[i][j], j, matrix)) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};
