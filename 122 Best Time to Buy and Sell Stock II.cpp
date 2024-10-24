class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int value1 = prices[0]; //buy price
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] > value1) { //stock is at a higher price than when we bought it so we sell 
                maxProfit += (prices[i] - value1);
            }
            value1 = prices[i]; //pretend we buy the newest stock every day
        }
        return maxProfit;
    }
};