class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        int i = 0, j = 0, n = nums.size();

        while(j < n){
            while(!dq.empty() and nums[dq.back()] < nums[j])
                dq.pop_back();
            dq.push_back(j);
            if(i > dq.front())
                dq.pop_front();
            if(j + 1 >= k){
                ans.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }

        return ans;
    }
};
