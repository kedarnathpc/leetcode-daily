class Solution {
public:
    int findDays(vector<int> &nums, int cap){
        int days = 1, load = 0;

        for(auto &i : nums){
            if(i + load > cap){
                days++;
                load = i;
            }
            else
                load += i;
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(findDays(weights, mid) <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
