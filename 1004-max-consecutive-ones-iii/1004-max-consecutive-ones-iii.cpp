class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int zero = 0;
        int maxcnt = 0;
        int left = 0;
        for(int right = 0;right<n;right++){
            if(nums[right]==0)zero++;
            if(zero > k){
                if(nums[left]==0)zero --;
                left++;
            }
            maxcnt = max(maxcnt,right-left+1);
        }
        return maxcnt;
    }
};