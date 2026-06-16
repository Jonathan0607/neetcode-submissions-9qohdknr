class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] <= nums[-1]: return nums[0]
        while len(nums) > 1:
            half = len(nums)//2
            if(nums[half] < nums[half-1]):
                return nums[half]
            elif nums[half] > nums[0]:
                nums = nums[half:]
            else:
                nums = nums[:half]
            