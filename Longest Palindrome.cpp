class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int odd = 0, even = 0, hasOdd = 0;

        for (auto &i : s)
            mp[i]++;
        
        for (auto &i : mp) {
            if (i.second & 1) {
                hasOdd = 1;
                odd += i.second - 1;
            }
            else
                even += i.second;
        }

        return hasOdd ? odd + even + 1 : odd + even;
    }
};
