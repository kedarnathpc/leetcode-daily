class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxi = INT_MIN, sum = 0;
        
        for(auto &i: nums){
            m[i]++;
            maxi = max(maxi, m[i]);
        }
        
        for(auto &i: m){
            if(i.second == maxi)
                sum += i.second;
        }
        
        return sum;
    }
};
