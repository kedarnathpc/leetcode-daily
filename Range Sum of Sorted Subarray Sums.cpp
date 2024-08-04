class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<long long> sums;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            long long curr_sum = 0;
            for (int j = i; j < n; ++j) {
                curr_sum = (curr_sum + nums[j]) % mod;
                sums.push_back(curr_sum);
            }
        }

        sort(sums.begin(), sums.end());

        for (int i = left - 1; i < right; ++i)
            result = (result + sums[i]) % mod;

        return result;
    }
};
