class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        dp = [0 for i in range(amount + 1)]
        dp[0] = 1
        for i in range(len(coins) - 1, -1, -1):
            for j in range(1, amount + 1):
                if j - coins[i] >= 0:
                    dp[j]+= dp[j - coins[i]]
        return dp[amount]