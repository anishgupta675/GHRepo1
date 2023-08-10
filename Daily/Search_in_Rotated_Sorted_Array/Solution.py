class Solution:
    def search(self, nums: list[int], low: int, high: int, target: int) -> int:
        if low > high:
            return -1
        mid = (low + mid) >> 1
        if nums[mid] == target:
            return mid
        if nums[low] <= nums[mid]:
            if target >= nums[low] and target <= nums[mid]:
                return self.search(nums, low, mid - 1, target)
            return self.search(nums, mid + 1, high, target)
        elif target >= nums[mid] and target <= nums[high]:
            return self.search(nums, mid + 1, high, target)
        return self.search(nums, low, mid - 1, target)
    def search(self, nums: list[int], target: int) -> int:
        return self.search(nums, 0, len(nums) - 1, target)