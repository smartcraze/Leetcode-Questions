class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxSum = 0;
        for (int i = 1; i < n; i += 2) {
            int sum = min(nums[i - 1], nums[i]);
            maxSum += sum;
        }
        return maxSum;
    }
};