class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int i, int target, vector<int> combination, vector<int>& candidates) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int index = i; index < candidates.size(); ++index) {
            if (index > i && candidates[index] == candidates[index - 1])
                continue;
            if (candidates[index] > target)
                break;
            combination.push_back(candidates[index]);  
            solve(index + 1, target - candidates[index], combination, candidates);  
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        solve(0, target, combination, candidates);
        return result;
    }
};
