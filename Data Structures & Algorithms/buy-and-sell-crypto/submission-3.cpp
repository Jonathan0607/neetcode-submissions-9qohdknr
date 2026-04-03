class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int buy = prices[0];
        int sell = 0;
        int profit = 0;

        
        for(int r = 1;r < prices.size(); r++){
            if(prices[r-1] < prices[l]){
                l = r-1;
            }
            if(prices[r] - prices[l] > profit){
                profit = prices[r] - prices[l];
            }
        }
        return profit;
    }
};
