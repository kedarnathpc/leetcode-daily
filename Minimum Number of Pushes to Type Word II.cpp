class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        int n = word.length();
        
        for(auto &i : word)
            m[i]++;
        
        int a = 1, ans = 0, it = 1;
        
        priority_queue<pair<int, char>> pq;
        for(auto &i : m){
            pq.push({i.second, i.first});
        }
        
        while(!pq.empty()){
            ans += (a * pq.top().first);
            pq.pop();
            if(it % 8 == 0)
                a++;
            it++;
        }

        return ans;
    }
};
