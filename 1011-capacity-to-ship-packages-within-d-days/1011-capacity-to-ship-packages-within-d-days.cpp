class Solution {
public:
    int sumofArray(vector<int>& weights){
        int sum = 0;
        for(int w : weights) sum += w;
        return sum;
    }

    int Helper(int capacity, vector<int>& weights){
        int days = 1;
        int load = 0;

        for(int w : weights){
            if(load + w > capacity){
                days++;
                load = w;
            } else {
                load += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mincap = *max_element(weights.begin(), weights.end());
        int maxcap = sumofArray(weights);

        while(mincap < maxcap){
            int mid = mincap + (maxcap - mincap) / 2;

            if(Helper(mid, weights) > days){
                mincap = mid + 1;   // capacity too small
            } else {
                maxcap = mid;       // try smaller capacity
            }
        }
        return mincap;
    }
};
