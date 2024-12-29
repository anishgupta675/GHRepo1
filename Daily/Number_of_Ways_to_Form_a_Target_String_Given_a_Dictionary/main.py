class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        mod, dp = (10 ** 9) + 7, [0] * (len(target) + 1)
        dp[0] = 1
        count = [[0] * 26] * len(words[0])
        for word in words:
            for i in range(len(words[0])):
                count[i][ord(word[i]) - ord('a')] += 1
        for i in range(len(words[0])):
            for j in range(len(target) - 1, -1, -1):
                dp[j + 1] += (dp[j] * count[i][ord(target[j]) - ord('a')]) % mod
                dp[j + 1] %= mod
        return dp[len(target)]
