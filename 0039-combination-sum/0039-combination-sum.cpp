class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, target, candidates, path, ans);
        return ans;
    }
    void backtrack(int idx, int target, vector<int>& candidates,
                   vector<int>& path, vector<vector<int>>& ans) {
        if (target < 0)
            return;
        if (target == 0){
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtrack(i, target - candidates[i], candidates, path, ans);
            path.pop_back();
        }
    }
};