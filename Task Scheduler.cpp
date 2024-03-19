class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nn = tasks.size(), count = 0;
        unordered_map<char, int> m;

        for(auto &i : tasks){
            m[i]++;
            count = max(count, m[i]);
        }

        int ans = (count - 1) * (n + 1);

        for(auto &i : m){
            if(i.second == count)
                ans++;
        }

        return max(nn, ans);
    }
};
