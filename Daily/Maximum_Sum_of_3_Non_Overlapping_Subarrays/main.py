class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        k_sums = [sum(nums[:k])]
        for i in range(k, len(nums)):
            k_sums.append(k_sums[-1] + nums[i] - nums[i - k])
        dp = {}

        def get_max_sum(i: int, count: int) -> int:
            if count == 3 or i > len(nums) - k:
                return 0
            if (i, count) in dp:
                return dp[(i, count)]
            include, skip = k_sums[i] + get_max_sum(i + k, count + 1), get_max_sum(i + 1, count)
            dp[(i, count)] = max(include, skip)
            return dp[(i, count)]

        def get_indices() -> List[int]:
            i, indices = 0, []
            while i <= len(nums) - k and len(indices) < 3:
                include, skip = k_sums[i] + get_max_sum(i + k, len(indices) + 1), get_max_sum(i + 1, len(indices))
                if include >= skip:
                    indices.append(i)
                    i += k
                else:
                    i += 1
            return indices
        return get_indices()
