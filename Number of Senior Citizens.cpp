class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto &s : details)
            count += (((s[11]-'0') * 10) + s[12]-'0') > 60;

        return count; 
    }
};
