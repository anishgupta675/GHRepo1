class Solution:
    def eventualSafeNodesUtil(self, index: int, vis: List[bool], graph: List[List[int]], unsafe: List[int]):
        safe = True
        for i in graph[index]:
            if vis[i] or unsafe[i] == 2:
                safe = False
                break
            if unsafe[i] == 1:
                continue
            vis[i] = True
            if not self.eventualSafeNodesUtil(i, vis, graph, unsafe):
                safe = False
            vis[i] = False
        unsafe[index] = 1 if safe else 2
        return safe

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        vis, unsafe = [False] * len(graph), [0] * len(graph)
        for i in range(len(graph)):
            if not unsafe[i]:
                vis[i] = True
                self.eventualSafeNodesUtil(i, vis, graph, unsafe)
                vis[i] = False
        res = []
        for i in range(len(unsafe)):
            if unsafe[i] == 1:
                res.append(i)
        return res
