class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res = "";

        for(auto &c : num){
            while(k && !st.empty() && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = (i == res.size()) ? "0" : res.substr(i);

        return res;
    }
};
