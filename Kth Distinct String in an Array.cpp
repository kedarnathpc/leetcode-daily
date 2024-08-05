class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, pair<int,int>> hash;

        for (int i = 0; i < arr.size(); ++i)
            hash[arr[i]] = {i, hash[arr[i]].second + 1};

        vector<pair<int,string>> strs;

        for (auto &h : hash)
            if (h.second.second == 1)
                strs.push_back({h.second.first, h.first});

        sort(strs.begin(), strs.end());

        if (k > 0 && k <= strs.size())
            return strs[k-1].second;

        return "";
    }
};
