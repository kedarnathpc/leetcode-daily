class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for(auto &i : s){
            if(i == '('){
                leftMin++;
                leftMax++;
            }
            else if(i == ')'){
                leftMin--;
                leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }
            if(leftMax < 0)
                return false;
            if(leftMin < 0)
                leftMin = 0;
        }

        return leftMin == 0;
    }
};
