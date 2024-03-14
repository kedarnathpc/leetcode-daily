class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int ans = 0, sum = 0;

        for(auto &i : nums){
            sum += i;
            if(sum == goal)
                ans++;
            if(m.find(sum - goal) != m.end())
                ans += m[sum-goal];
            m[sum]++;
        }

        return ans;
    }
};
