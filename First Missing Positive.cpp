class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int a = 1;
        while(a<=nums.size()){
            if(s.find(a)==s.end()){
                return a;
            }
            else{
                a++;
            }
        }
        return a;
    }
};
