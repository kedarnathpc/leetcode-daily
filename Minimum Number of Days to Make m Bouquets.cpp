class Solution {
public:
    bool isPossible(vector<int> &nums, int &m, int &k, long long &day){
        long long cnt = 0, cntFlowers = 0, n = nums.size();

        for(long long i = 0; i < n; ++i){
            if(nums[i] <= day)
                cnt++;
            else{
                cntFlowers += (cnt/k);
                cnt = 0;
            }
        }
        cntFlowers += (cnt/k);

        return cntFlowers >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();

        if((long long)m*k > n)
            return -1;

        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans = high;

        while(low <= high){
            long long mid = low + (high-low)/2;
            
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};
