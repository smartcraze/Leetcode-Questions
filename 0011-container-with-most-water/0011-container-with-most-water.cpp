class Solution {
public:
    int maxArea(vector<int>& height) {
        int  maxwater = INT_MIN;
        int left = 0;
        int right = height.size()-1;
        while(left <=right){
            int h = min(height[left],height[right]);
            int len = right-left;
            int area = h * len;
            maxwater = max(maxwater, area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxwater;
    }
};