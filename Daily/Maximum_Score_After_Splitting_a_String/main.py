class Solution:
    def maxScore(self, s: str) -> int:
        ones, zeroes, max_val = 0, 0, -inf
        for i in range(len(s) - 1):
            if s[i] == "1":
                ones += 1
            else:
                zeroes += 1
            max_val = max(max_val, zeroes - ones)
        if s[-1] == "1":
            ones += 1
        return max_val + ones
