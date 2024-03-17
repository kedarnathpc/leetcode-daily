class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& ni) {
        int n = arr.size();
        vector<vector<int>> ans;
        int i = 0;

        while(i < n and arr[i][1] < ni[0]){
            ans.push_back(arr[i]);
            i++;
        }

        while(i < n and ni[1] >= arr[i][0]){
            ni[0] = min(ni[0], arr[i][0]);
            ni[1] = max(ni[1], arr[i][1]);
            i++;
        }
        ans.push_back(ni);

        while(i < n){
            ans.push_back(arr[i]);
            i++;
        }

        return ans;
    }
};
