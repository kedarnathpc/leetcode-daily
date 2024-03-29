class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0, n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int left = 0, right = 0;

        while(right < n){
            k -= (nums[right++] == maxi);
            while(k == 0)
                k += (nums[left++] == maxi);
            count += left;
        }

        return count;
    }
};
