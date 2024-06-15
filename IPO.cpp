class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> v;
        int n = profits.size();

        for (int i = 0; i < n; ++i)
            v.push_back({capital[i], profits[i]});

        sort(v.begin(), v.end(), cmp);

        priority_queue<int> maxHeap;
        int i = 0;

        while (k--) {
            while (i < n && v[i].first <= w) {
                maxHeap.push(v[i].second);
                ++i;
            }

            if (maxHeap.empty())
                break;

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
