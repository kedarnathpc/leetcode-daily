class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> m;
        int maxi = INT_MIN;

        for (auto &i : nums)
            m.insert(i);

        for (auto &i : m) {
            if (m.find(i * -1) != m.end())
                maxi = max(maxi, abs(i));
        }

        return maxi == INT_MIN ? -1 : maxi;
    }
};
