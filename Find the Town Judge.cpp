class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> m;
        
        if(n == 1)
            return 1;
            
        for(auto &i : trust){
            m[i[1]]++;
            m[i[0]]--;
        }

        for(auto &i : m)
            if(i.second == n-1)
                return i.first;
        
        return -1;
    }
};
