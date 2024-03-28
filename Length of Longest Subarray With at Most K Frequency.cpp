class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 0, n = nums.size(), i = 0, j = 0;
        unordered_map<int,int> m;

        while(j < n){
            m[nums[j]]++;
            while(i < j and m[nums[j]] > k){
                m[nums[i++]]--;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};
