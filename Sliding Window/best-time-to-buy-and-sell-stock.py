'''
* Best Time To Buy And Sell Stock: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
'''

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        One-pass solution for 'Best Time to Buy and Sell Stock'.
        Time: O(n), Space: O(1)
        """
        if not prices:
            return 0
        
        maxProfit = 0
        minPrice = prices[0]
        
        for i in range(1, len(prices)):
            minPrice = min(minPrice, prices[i])
            maxProfit = max(maxProfit, prices[i] - minPrice)
        
        return maxProfit


# ---- Run some quick checks when executed directly ----
if __name__ == "__main__":
    s = Solution()

    # Basic tests
    assert s.maxProfit([7,1,5,3,6,4]) == 5   # Buy at 1, sell at 6
    assert s.maxProfit([7,6,4,3,1]) == 0     # No profit possible
    assert s.maxProfit([1,2]) == 1           # Buy at 1, sell at 2
    assert s.maxProfit([2,4,1]) == 2         # Buy at 2, sell at 4
    assert s.maxProfit([]) == 0              # Empty list -> 0

    print("All tests passed ✅")
    # Example usage:
    example = [7,1,5,3,6,4]
    print(f"maxProfit({example}) = {s.maxProfit(example)}")
