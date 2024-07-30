class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> countA(n, 0);
        int result = INT_MAX;

        countA[n - 1] = (s[n - 1] == 'a') ? 1 : 0;
        for (int i = n - 2; i >= 0; --i)
            countA[i] = countA[i + 1] + (s[i] == 'a' ? 1 : 0);
        
        int countB = 0;

        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i - 1] == 'b')
                countB++;
            if (i < n - 1)
                result = min(result, countA[i + 1] + countB);
            else
                result = min(result, countB); 
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
