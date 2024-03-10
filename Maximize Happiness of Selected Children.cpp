class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long sum = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int i = 0, a = 0;
        while(k--){
            int temp = nums[i] - a;
            if(temp > 0)
                sum += temp;
            i++;
            a++;
        }
        
        return sum;
    }
};
