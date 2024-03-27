class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        
        int j = 0, count = 0, n = nums.size();
        long long product = 1;

        for(int i = 0; i < n; ++i){
            product *= nums[i];
            while(product >= k){
                product /= nums[j];
                j++;
            }
            count += (i - j + 1);
        }

        return count;
    }
};
