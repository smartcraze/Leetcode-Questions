class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxarea = 0;
        while(left<right){
            int h = min(height[left],height[right]);
            int w = right-left;
            int area = h*w;
            maxarea = max(maxarea,area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxarea;
    }
};