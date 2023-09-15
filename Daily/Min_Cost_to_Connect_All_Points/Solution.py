import heapq

class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        res = 0
        vis = set()
        min_heap = [[0, 0]]
        adj = { i : [] for i in range(len(points)) }
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                adj[i].append([abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j])
                adj[j].append([abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i])
        while len(vis) < len(points):
            cost, i = heapq.heappop(min_heap)
            if i not in vis:
                res+= cost
                vis.add(i)
                for j, k in adj[i]:
                    if k not in vis:
                        heapq.heappush(min_heap, [j, k])
        return res