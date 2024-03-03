class Solution {
public:
    long long sumOfArray(vector<int> &nums, int &k, int &divisor){
        long long sum = 0;
        for(auto &i : nums)
            sum += ceil((double)(i) / (double)divisor);
       
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int k) {
        long long n = nums.size();

        if(n > k)
            return -1;

        long long low = 1;
        long long high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            if(sumOfArray(nums, k, mid) <= k){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return low;
    }
};
