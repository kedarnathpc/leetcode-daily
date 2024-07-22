class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> arr;

        for (int i = 0; i < names.size(); ++i)
            arr.push_back({heights[i], names[i]});

        sort(arr.rbegin(), arr.rend());

        vector<string> result;
        
        for (auto &a : arr)
            result.push_back(a.second);

        return result;
    }
};
