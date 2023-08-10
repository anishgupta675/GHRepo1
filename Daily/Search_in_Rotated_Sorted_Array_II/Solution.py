class Solution:
    def binarySearch(self, nums: list[int], low: int, high: int, target: int) -> bool:
        if low > high:
            return False
        mid = (low + high) >> 1
        if nums[mid] == target:
            return True
        if nums[low] == nums[mid] and nums[mid] == nums[high]:
            return self.binarySearch(nums, low + 1, high - 1, target)
        if nums[low] <= nums[mid]:
            if target >= nums[low] and target <= nums[mid]:
                return self.binarySearch(nums, low, mid - 1, target)
            return self.binarySearch(nums, mid + 1, high, target)
        if target >= nums[mid] and target <= nums[high]:
            return self.binarySearch(nums, mid + 1, high, target)
        return self.binarySearch(nums, low, mid - 1, target)
    def search(self, nums: list[int], target: int) -> bool:
        return self.binarySearch(nums, 0, len(nums) - 1, target)