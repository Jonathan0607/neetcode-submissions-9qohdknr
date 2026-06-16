class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best_sell = prices[0]
        profit = 0
        for i in range(1,len(prices)):
            if prices[i-1] < best_sell:
                best_sell = prices[i-1]
            if prices[i]-best_sell > profit:
                profit = prices[i]-best_sell 
        return profit