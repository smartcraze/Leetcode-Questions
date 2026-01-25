class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minsize = INT_MAX;
        int left = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
           while(sum>=target){
            minsize = min(minsize,i-left+1);
            sum-=nums[left];
            left++;
           }
        }
        return minsize == INT_MAX ? 0 : minsize;
    }
};