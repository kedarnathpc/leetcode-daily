class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0, maxi = 0, n = customers.size();

        for (int i = 0; i < n; ++i)
            if (!grumpy[i])
                sum += customers[i];

        int un = 0;
        for (int i = 0; i < minutes; ++i)
            if (grumpy[i])
                un += customers[i];

        maxi = un;
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i-minutes])
                un -= customers[i-minutes];
            if (grumpy[i])
                un += customers[i];
            maxi = max(maxi, un);
        }

        return sum + maxi;
    }
};
