class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix = 0;
        int maxPrefix = 0;
        int minPrefix = 0;

        for (int num : nums) {
            prefix += num;
            maxPrefix = max(maxPrefix, prefix);
            minPrefix = min(minPrefix, prefix);
        }

        return maxPrefix - minPrefix;
    }
};