class Solution {
public:
    vector<int> row = {1, -1, 0, 0}, col = {0, 0, -1, 1};

    int solve (int i, int j, int m, int n, vector<vector<int>> &grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        
        int curr = grid[i][j];
        grid[i][j] = 0;
        int localMax = curr;

        for (int k = 0; k < 4; ++k) {
            int newI = i + row[k], newJ = j + col[k];
            localMax = max(localMax, curr + solve(newI, newJ, m, n, grid));
        }

        grid[i][j] = curr;
        return localMax;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0)
                    maxi = max(maxi, solve(i, j, m, n, grid));
            }
        }

        return maxi;
    }
};
