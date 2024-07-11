class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> index;;
        vector<char> res;

        for (char c : s) {
            if (c == '(')
                index.push(res.size());
            else if (c == ')') {
                int start = index.top();
                index.pop();
                reverse(res.begin() + start, res.end());
            }
            else
                res.push_back(c);
        }

        return string(res.begin(), res.end());
    }
};
