class Solution:

    direction = [
        [
            0,
            1
        ],
        [
            0,
            -1
        ],
        [
            1,
            0
        ],
        [
            -1,
            0
        ]
    ]

    def dfs(self, grid: List[List[int]], r: int, c: int, dp: List[List[int]], cost: int, bfs: List[List[int]]) -> None:
        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or dp[r][c] != float("inf"):
            return
        dp[r][c] = cost
        bfs.append([r, c])
        self.dfs(grid, r + self.direction[grid[r][c] - 1][0], c + self.direction[grid[r][c] - 1][0], dp, cost, bfs)

    def minCost(self, grid: List[List[int]]) -> int:
        cost, dp = 0, []
        for i in range(len(grid)):
            dp.append([float("inf")] * len(grid[0]))
        bfs = []
        self.dfs(grid, 0, 0, dp, cost, bfs)
        while bfs:
            cost += 1
            for i in range(len(bfs), 0, -1):
                top = bfs[0]
                bfs.pop()
                for j in range(4):
                    self.dfs(grid, top[0] + self.direction[j][0], top[1] + self.direction[i][1], dp, cost, bfs)
        return dp[len(grid) - 1][len(grid[0]) - 1]
