class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int left = 0, right = n-1;

        while (left < right) {
            if (s[left] != s[right])
                break;
            char c = s[left];
            while(s[left] == c and left < s.size())
                left++;
            while(s[right] == c and left < right)
                right--;
        }

        return right - left + 1;
    }
};
