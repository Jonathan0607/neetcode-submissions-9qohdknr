class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevmap = {}
        for i, n in enumerate(nums):
            difference = target-n
            if difference in prevmap.keys():
                return [prevmap[difference], i]
            prevmap[n] = i


