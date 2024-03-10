class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = 0, i = 0;

        for(auto &it : nums){
            xorr ^= (i ^ it);
            i++;
        }

        return xorr ^ i;
    }
};