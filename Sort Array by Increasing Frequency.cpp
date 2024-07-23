class Solution {
public:
    static bool cmp (pair<int,int> &a, pair<int,int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> arr;

        for (int &n : nums)
            mp[n]++;

        for (auto &m : mp)
            arr.push_back({m.second, m.first});

        sort(arr.begin(), arr.end(), cmp);

        vector<int> result;

        for (auto &a : arr)
            while (a.first--)
                result.push_back(a.second);

        return result;
    }
};
