class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = defaultdict(list)
        for i, j in edges:
            adj[i].append(i)
            adj[j].append(i)
        res = 0
        def dfs(cur, parent):
            total = values[cur]
            for child in adj[cur]:
                if child != parent:
                    total += dfs(child, cur)
            if total % k == 0:
                nonlocal res
                res += 1
            return total
        dfs(0, -1)
        return res
