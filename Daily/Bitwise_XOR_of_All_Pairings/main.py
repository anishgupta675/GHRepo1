class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        freq = {}
        for i in nums1:
            freq[i] = freq.get(i, 0) + len(nums2)
        for i in nums2:
            freq[i] = freq.get(i, 0) + len(nums1)
        ans = 0
        for i in freq:
            if freq[i] % 2:
                ans ^= i
        return ans
