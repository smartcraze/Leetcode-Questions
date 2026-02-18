class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax = nums[0];
        int currmin = nums[0];
        int maximum = nums[0];
        int minimum = nums[0];
        for(int i = 1; i<nums.size();i++){
            int num = nums[i];
            currmax = max(num,currmax+num);
            currmin = min(num,currmin+num);
            maximum = max(maximum,currmax);
            minimum = min(minimum,currmin);
        }
        return max(abs(maximum),abs(minimum));
        
    }
};