class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            
            while (!q.empty() && i > q.front() + k - 1)
                q.pop();
            
            if ((nums[i] + q.size()) % 2 == 0) {
                if (i + k > nums.size())
                    return -1;
                res++;
                q.push(i);
            }
        }   

        return res;
    }
};
