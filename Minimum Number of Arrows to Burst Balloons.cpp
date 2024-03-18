class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int count = 1;
        int y = points[0][1];

        for(int i = 1; i < n; ++i){
            if(points[i][0] > y){
                count++;
                y = points[i][1];
            }
            y = min(points[i][1], y);
        }

        return count;
    }
};
