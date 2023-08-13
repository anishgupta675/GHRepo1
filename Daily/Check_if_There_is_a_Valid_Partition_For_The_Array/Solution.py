class Solution:
    def validPartition(self, nums: list[int]) -> bool:
        if len(nums) == 2:
            return nums[-1] == nums[-2]
        dp = [nums[-1] == nums[-2] == nums[-3] or nums[-3] + 1 == nums[-2] == nums[-1] - 1, nums[-1] == nums[-2], False]
        for i in range(len(nums) - 4, -1, -1):
            cur = (nums[i] == nums[i + 1]) and dp[1] or (
                (nums[i] == nums[i + 1] == nums[i + 2] or
                nums[i] + 1 == nums[i + 1] == nums[i + 2] - 1) and
                dp[2]
            )
            dp = [cur, dp[0], dp[1]]
        return dp[0]