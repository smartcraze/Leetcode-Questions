class Solution {
public:
    void solve(int index, vector<int> nums, vector<vector<int>>& ans,
               vector<int> subset) {

        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        // pick
        subset.push_back(nums[index]);
        solve(index + 1, nums, ans,subset);
        subset.pop_back();

        // not pick
        solve(index + 1, nums, ans,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0, nums, ans, subset);
        return ans;
    }
};