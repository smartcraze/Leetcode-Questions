class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);
        return ans;
    }
    void backtrack(int idx, vector<int>& nums, vector<int>& path,
                   vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};