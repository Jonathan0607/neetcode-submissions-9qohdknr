class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best_buy = prices[0]
        profit = 0
        for i in prices[1:]:
            profit = max(profit, i-best_buy)
            best_buy = min(i, best_buy)
        return profit