class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        res = [[] for i in range(numRows)]
        res[0].append(1)
        for i in range(1, numRows):
            for j in range(i + 1):
                if not j or j == i:
                    res[i].append(1)
                else:
                    res[i].append(res[i - 1][j - 1] + res[i - 1][j])
        return res