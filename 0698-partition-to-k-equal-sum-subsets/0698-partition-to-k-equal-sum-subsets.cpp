class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%k != 0) return false;
        int target = total/k;
        sort(nums.rbegin(),nums.rend());
        vector<int>bucket(k,0);
        return backtrack(0,nums,target,bucket); 
    }
    bool backtrack(int idx, vector<int>& nums, int target,vector<int>& bucket){
        if(idx==nums.size()) return true;
        for(int i = 0;i<bucket.size();i++){
            if(nums[idx]+bucket[i]>target) continue;
            bucket[i] +=nums[idx];
            if(backtrack(idx+1,nums,target,bucket)) return true;
            bucket[i] -= nums[idx];
            if (bucket[i] == 0) break;
        }
        return false;
    }
};