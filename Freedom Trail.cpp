class Solution {
public:
    int solve(int r, int k, string &ring, string &key, vector<vector<int>> &dp) {
        if (k == key.length())
            return 0;

        if (dp[r][k] != -1)
            return dp[r][k];
        
        int res = INT_MAX;

        for (int i = 0; i < ring.size(); ++i) {
            if (ring[i] == key[k]) {
                int mini_dist = min(abs(r - i), static_cast<int>(ring.size()) - abs(r - i));
                res = min(res, mini_dist + 1 + solve(i, k + 1, ring, key, dp));
            }
        }

        return dp[r][k] = res;
    }

    int findRotateSteps(string ring, string key) {
        int r = ring.size(), k = key.size();
        vector<vector<int>> dp(r, vector<int>(k, -1));
        return solve(0, 0, ring, key, dp);
    }
};
