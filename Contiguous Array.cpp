class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum = 0, maxi = 0, ind = 0;
        m[0] = -1;

        for(auto &i : nums){
            sum += (i == 1) ? 1 : -1;
            (m.find(sum) != m.end()) ? maxi = max(maxi, ind - m[sum]) : m[sum] = ind;
            ind++;
        }

        return maxi;
    }
};
