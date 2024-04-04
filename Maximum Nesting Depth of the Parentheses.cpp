class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxi = 0;

        for(auto &i : s){
            if(i == '(')
                cnt++;
            else if(i == ')')
                cnt--;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};
