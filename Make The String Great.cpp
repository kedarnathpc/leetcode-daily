class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans = "";

        for(auto &i : s){
            if(!st.empty() and ((st.top() == i+32) or (st.top()+32 == i)))
                st.pop();
            else
                st.push(i);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
