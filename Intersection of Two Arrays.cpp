class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m1;
        set<int> s;

        for(auto &i : nums1)
            m1[i]++;

        for(auto &i : nums2)
            if(m1.find(i) != m1.end())
                s.insert(i);
        
        for(auto &i : s)
            ans.push_back(i);

        return ans;
    }
};
