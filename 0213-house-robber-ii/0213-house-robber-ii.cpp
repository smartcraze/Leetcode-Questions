class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(robLinear(nums, 0, n-2),
                   robLinear(nums, 1, n-1));
    }

    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0; // dp[i+1]
        int prev2 = 0; // dp[i+2]

        for(int i = end; i >= start; i--) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};