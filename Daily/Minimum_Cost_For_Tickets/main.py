class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp, travel_days = [0] * 366, set()
        for i in days:
            travel_days.add(i)
            for i in range(1, 366):
                if i in travel_days:
                    dp[i] = dp[i - 1]
                else:
                    dp[i] = min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2], dp[i - 1] + costs[0])
        return dp[365]
