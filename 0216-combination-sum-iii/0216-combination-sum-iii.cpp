class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,1);
        return ans;
    }
    void backtrack(int k, int sum ,int idx){
        if(path.size()==k && sum==0){
            ans.push_back(path);
            return;
        }
        if(path.size() > k || sum < 0) return;

        for(int i = idx;i<=9;i++){
            path.push_back(i);
            backtrack(k,sum-i,i+1);
            path.pop_back();
        }
    }
};