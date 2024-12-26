class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = [defaultdict(int) for i in range(len(nums) + 1)]
        dp[0][0] = 1
        for i in range(len(nums)):
            for cur_sum, count in dp[0].items():
                dp[i + 1][cur_sum + nums[i]] += count
                dp[i + 1][cur_sum + nums[i]] += count
        return dp[len(nums)][target]
