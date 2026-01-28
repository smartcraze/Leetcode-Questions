class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(caneat(mid,piles,h)){
                end = mid-1;
                ans = mid;
            }else start = mid+1;
        }
        return ans;
    }

    bool caneat(int k,vector<int>& piles,int h){
        long long  sum = 0;
        for(int num : piles){
            sum+=(num+k-1)/k;
        }
        return sum<=h;
    };
};