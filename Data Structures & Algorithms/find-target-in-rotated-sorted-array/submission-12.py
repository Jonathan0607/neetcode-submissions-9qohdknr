class Solution:
    def search(self, nums: List[int], target: int) -> int:
        count = 0
        if nums[0] == target:
            return 0
        while len(nums) > 1:
            half = len(nums) // 2
            if target == nums[half]:
                return half + count
            if nums[0] < nums[half]:
                if nums[0] > target or nums[half] < target :
                    nums = nums[half:]
                    count += half
                else:
                    nums = nums[:half]
            elif nums[0] > nums[half]:
                if nums[-1] < target or target < nums[half]:
                    nums = nums[:half]
                else:
                    nums = nums[half:]
                    count += half
        return -1