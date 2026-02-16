class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int maxSum = nums[0];
        int currMax = 0;

        int minSum = nums[0];
        int currMin = 0;

        for(int num : nums)
        {
            totalSum += num;

            // Kadane for max
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Kadane for min
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        // special case: all negative
        if(maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};
