class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        pivot, left, mid, right = nums[0], [], [], []
        for x in nums:
            if x > pivot:
                right.append(x)
            elif x < pivot:
                left.append(x)
            else:
                mid.append(x)
        if k <= len(right):
            return self.findKthLargest(right, k)
        if k > len(right) + len(mid):
            return self.findKthLargest(left, k - len(right) - len(mid))
        return mid[0]