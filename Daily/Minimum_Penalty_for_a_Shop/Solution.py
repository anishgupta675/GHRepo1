class Solution:
    def bestClosingTime(self, customers: str) -> int:
        prefix_n = [0] * (len(customers) + 1)
        postfix_y = [0] * (len(customers) + 1)
        for i in range(1, len(customers) + 1):
            prefix_n[i] = prefix_n[i - 1]
            if customers[i - 1] == "N":
                prefix_n[i] += 1
        for i in range(len(customers) - 1, -1, -1):
            postfix_y[i] = postfix_y[i + 1]
            if customers[i] == "Y":
                postfix_y[i] += 1
        min_penalty, idx = float("inf"), 0
        for i in range(len(customers) + 1):
            penalty = prefix_n[i] + postfix_y[i]
            if penalty < min_penalty:
                min_penalty = penalty
                idx = i
        return idx