class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int start, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            curr.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target);
        return ans;
    }
};