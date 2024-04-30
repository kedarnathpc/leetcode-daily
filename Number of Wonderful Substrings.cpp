class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> m;
        m[0] = 1;

        long long prefix = 0, res = 0;
        for (auto &c : word) {
            prefix = (prefix ^ (1 << (c - 'a')));
            res += m[prefix];

            for (char ch = 'a'; ch <= 'j'; ch++) {
                long long odd = (prefix ^ (1 << (ch-'a')));
                res += m[odd];
            }

            m[prefix]++;
        }

        return res;
    }
};
