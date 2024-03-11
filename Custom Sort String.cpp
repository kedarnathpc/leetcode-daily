class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        string ans = "";

        for(auto &i : order)
            m[i] = 0;

        for(auto &i : s)
            if(m.find(i) != m.end())
                m[i]++;

        for(auto &i : order)
            ans.append(m[i], i);

        for(auto &i : s)
            if(m.find(i) == m.end())
                ans += i;

        return ans;   
    }
};
