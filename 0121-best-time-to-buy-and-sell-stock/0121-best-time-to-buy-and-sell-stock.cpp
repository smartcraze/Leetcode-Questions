class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxProfit = 0;
        for(int price : prices){
            minprice = min(minprice,price);
            maxProfit = max(price-minprice, maxProfit);
        }

        return maxProfit;
        
    }
};