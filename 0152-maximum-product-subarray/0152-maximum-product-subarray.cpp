class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int currmax = nums[0];
        int currmin = nums[0];
        int globalmax = nums[0];
        
        for(int i=1;i<n;i++){
            int num = nums[i];
            if(num<0){
                swap(currmax,currmin);
            }
            currmax = max(num,currmax*num);
            currmin = min(num,currmin*num);

            globalmax = max(globalmax,currmax);
        }
        return globalmax;
        
    }
};