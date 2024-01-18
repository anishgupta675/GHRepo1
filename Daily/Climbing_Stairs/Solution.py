class Solution:
    dp = [0] * 100
    def climbStairs(self, n: int) -> int:
        if n == 1:
            self.dp[n] = 1
            return self.dp[n]
        if n == 2:
            self.dp[n] = 2
            return self.dp[n]
        if self.dp[n]:
            return self.dp[n]
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)