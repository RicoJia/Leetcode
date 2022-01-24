# 2022-01-15
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        s = 0
        cb = 100000
        for p in prices: 
            if p - cb > 0:
                s += (p-cb)
                cb = 100000
            # Lucky: you don't want elif, because you can "buy" it if at a later time you see a buying opportunity
            if p < cb:
                cb = p
        return s
