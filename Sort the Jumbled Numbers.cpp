class Solution {
public:
    static bool cmp(pair<pair<int,int>, int>& a, pair<pair<int,int>, int>& b) {
        if (a.first.second == b.first.second)
            return a.second < b.second;
        return a.first.second < b.first.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<pair<int,int>, int>> arr; // {{nums[i], converted[i]}, index}

        for (int i = 0; i < nums.size(); ++i) {
            string str = to_string(nums[i]);
            for (int j = 0; j < str.size(); ++j) {
                str[j] = '0' + mapping[str[j] - '0'];
            }
            int n = stoi(str);
            arr.push_back({{nums[i], n}, i});
        }

        sort(arr.begin(), arr.end(), cmp);

        vector<int> result;
        for (auto& a : arr)
            result.push_back(a.first.first);

        return result;
    }
};
