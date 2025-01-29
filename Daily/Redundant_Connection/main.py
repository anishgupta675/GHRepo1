class Solution:
    def checkPath(self, src: int, tgt: int, vis: List[bool], adj: List[List[int]]) -> bool:
        vis[src] = 1
        if src == tgt:
            return 1
        flag = 0
        for i in adj[src]:
            if not vis[i]:
                flag = flag or self.checkPath(i, tgt, vis, adj)
        return flag

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        adj = [[]] * len(edges)
        for i in edges:
            vis = [0] * len(edges)
            if self.checkPath(i[0] - 1, i[1] - 1, vis, adj):
                return i
            adj[i[0] - 1].append(i[1] - 1)
            adj[i[1] - 1].append(i[0] - 1)
        return []
