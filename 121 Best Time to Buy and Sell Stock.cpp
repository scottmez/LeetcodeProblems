class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int value1 = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int tempProfit = prices[i] - value1;
            if (tempProfit > maxProfit) {
                maxProfit = tempProfit;
            }
            else if (value1 > prices[i]) {
                value1 = prices[i];
            }
        }
        return maxProfit;
    }  
};