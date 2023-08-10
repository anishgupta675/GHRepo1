class Solution:
    ans = 0
    def check(self, nums: list[int], p: int, mid: int) -> bool:
        i, cnt = 0, 0
        while i < len(nums) - 1:
            if abs(nums[i] - nums[i + 1]) <= mid:
                cnt += 1
                i += 2
            else:
                i += 1
            if cnt == p:
                return True
            else:
                return False
    def minimizeMax(self, nums: list[int], p: int) -> int:
        if not p:
            return 0
        nums.sort()
        def binarySearch(nums: list[int], low: int, high: int):
            if low > high:
                return
            mid = (low + high) >> 1
            if self.check(nums, p, mid):
                self.ans = mid
                binarySearch(nums, low, mid - 1)
            else:
                binarySearch(nums, mid + 1, high)
        binarySearch(nums, 0, 10**9 + 7)
        return self.ans