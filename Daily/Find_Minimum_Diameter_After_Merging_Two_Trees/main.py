class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: list[list[int]], edges2: list[list[int]]) -> int:
        adj_list1, adj_list2 = self.build_adj_list(len(edges1) + 1, edges1), self.build_adj_list(len(edges2) + 1, edges2)
        diameter1, max_depth = self.find_diameter(adj_list1, 0, -1)
        diameter2, max_depth = self.find_diameter(adj_list2, 0, -1)
        combined_diameter = ceil(diameter1 / 2) + ceil(diameter2 / 2) + 1
        return max(diameter1, diameter2, combined_diameter)
    
    def build_adj_list(self, size: int, edges: list[list[int]]) -> list[list[int]]:
        adj_list = [[] for i in range(size)]
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        return adj_list
    
    def find_diameter(self, adj_list: list[list[int]], node: int, parent: int) -> tuple[int, int]:
        max_depth1 = max_depth2 = (0)
        diameter = 0
        for edge in adj_list[node]:
            if edge == parent:
                continue
            child_diameter, depth = self.find_diameter(adj_list, edge, node)
            depth += 1
            diameter = max(diameter, child_diameter)
            if depth > max_depth1:
                max_depth2 = max_depth1
                max_depth1 = depth
            elif depth > max_depth2:
                max_depth2 = depth
        diameter = max(diameter, max_depth1 + max_depth2)
        return diameter, max_depth1
