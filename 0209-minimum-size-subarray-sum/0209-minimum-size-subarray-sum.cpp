class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = INT_MAX;
        int start = 0;
        int sum = 0;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while(sum >= target) {
                sum-=nums[start];
                count = min(count, end - start + 1);
                start++;
            }
        }
        return count == INT_MAX ? 0 : count;
    }
};