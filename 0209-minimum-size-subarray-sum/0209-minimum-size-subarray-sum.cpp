class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = INT_MAX;
        int n = nums.size();
        int sum = 0;

        int j = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            while(sum >=target){
                sum-=nums[j];
                count = min(count , i-j+1);
                j++;
            }   
        }
        return count == INT_MAX  ? 0 : count;
        
    }
};