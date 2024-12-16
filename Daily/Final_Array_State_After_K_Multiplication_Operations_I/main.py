class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int):
        pq = [(val, i) for i, val in enumerate(nums)]
        heapify(pq)
        for i in range(k):
            i, j = heappop(pq)
            nums[j] *= multiplier
            heappush(pq, (nums[j], j))
        return nums
