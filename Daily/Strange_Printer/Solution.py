from math import inf

class Solution:
    def __method1(self, start, end, s):
        if start == end:
            return 1
        if self.dp[start][end] != None:
            return self.dp[start][end]
        ans = inf
        for i in range(start, end):
            ans = min(
                ans,
                self.__method(start, i, s) + self.__method1(i + 1, end, s)
            )
        if s[start] == s[end]:
            ans -= 1
        self.dp[start][end] = ans
        return ans
    
    def __method1_handler(self, s):
        self.dp = [[None for j in range(len(s))] for i in range(len(s))]
        return self.__method1(0, len(s) - 1, s)
    
    def __method2(self, s):
        dp = [[None for j in range(len(s))] for i in range(len(s))]
        for start in range(len(s) - 1, -1, -1):
            for end in range(start, len(s)):
                if start == end:
                    dp[start][end] = 1
                    continue
                ans = inf
                for i in range(start, end):
                    ans = min(ans, dp[start][i] + dp[i + 1][end])
                if s[start] == s[end]:
                    ans -= 1
                dp[start][end] = ans
        return dp[0][len(s) - 1]
    
    def strangePrinter(self, s: str) -> int:
        return self.__method2(s)