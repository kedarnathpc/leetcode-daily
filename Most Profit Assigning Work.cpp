class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<pair<int,int>> v;
    
        for (int i = 0; i < n; ++i)
            v.push_back({difficulty[i], profit[i]});

        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());

        int i = 0, maxi = 0, res = 0;
        
        for (auto work : worker) {
            while (work >= v[i].first && i < worker.size())
                maxi = max(maxi, v[i++].second);
            res += maxi;
        }

        return res;
    }
};
