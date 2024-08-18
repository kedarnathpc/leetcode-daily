class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(1);
        seen.insert(1);
        
        long long curr;
        while (n--) {
            curr = pq.top();
            pq.pop();
            for (auto &f: factors) {
                long long newNumber = curr * f;
                if (seen.find(newNumber) == seen.end()) {
                    seen.insert(newNumber);
                    pq.push(newNumber);
                }
            }
        }

        return curr;
    }
};
