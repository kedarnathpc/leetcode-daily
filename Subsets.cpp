class Solution {
public:
    void solve (int i, vector<int> &nums, vector<int> temp, vector<vector<int>> &res) {
        if (i < 0) {
            res.push_back(temp);
            return;
        }

        // not pick
        solve (i-1, nums, temp, res);
        
        // pick
        temp.push_back(nums[i]);
        solve (i-1, nums, temp, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        solve (nums.size()-1, nums, temp, res);

        return res;
    }
};
