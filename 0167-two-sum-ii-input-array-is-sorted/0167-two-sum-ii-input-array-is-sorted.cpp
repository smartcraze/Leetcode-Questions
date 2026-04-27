class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0 ,j = nums.size()-1;
        while(i<j){
            int add = nums[i]+nums[j];
            if(add==target) return {i+1,j+1};
            else if(add >target) j--;
            else i++;
        }
        return {-1,-1};
        
    }
};