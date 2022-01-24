# 2022-01-13
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        chest = [[]]
        for idx, num in enumerate(nums):
            temp_chest = []
            for ls in chest: 
                for i in range(idx + 1): 
                    temp = ls.copy()
                    temp.insert(i, nums[idx])
                    temp_chest.append(temp)
            chest = temp_chest
        return chest
