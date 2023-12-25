class Solution:
    def ways(self, i, s, dp):
        if i == len(s):
            return 1
        if s[i] == '0':
            return 0
        if dp[i] != -1:
            return dp[i]
        x = self.ways(i + 1, s, dp)
        y = 0
        if i < len(s) - 1 and (s[i] == '1' or s[i] == '2' and s[i + 1] <= '6'):
            y += self.ways(i + 2, s, dp)
        dp[i] = x + y
        return dp[i]
    def numDecodings(self, s: str) -> int:
        dp = [-1] * len(s)
        return self.ways(0, s, dp)