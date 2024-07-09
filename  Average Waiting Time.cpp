class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available = 0;
        double wait = 0.0;

        for (auto &c : customers) {
            int arrival = c[0];
            int time = c[1];
            available = max(available, arrival) + time;
            wait += available - arrival;
        }

        return (double) wait / customers.size();
    }
};
