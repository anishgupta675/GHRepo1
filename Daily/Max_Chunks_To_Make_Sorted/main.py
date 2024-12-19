class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        max_val, count = 0, 0
        for i in range(len(arr)):
            max_val = max(arr[i], max_val)
            if i == max_val:
                count += 1
        return count
