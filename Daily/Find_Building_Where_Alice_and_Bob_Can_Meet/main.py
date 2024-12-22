class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        max_index, res, store_queries = [], [-1] * len(queries), [[] for i in heights]
        for index, query in enumerate(queries):
            a, b = query
            if a < b and heights[a] < heights[b]:
                res[index] = b
            elif a > b and heights[a] > heights[b]:
                res[index] = a
            elif a == b:
                res[index] = a
            else:
                store_queries[max(a, b)].append((max(heights[a], heights[b]), index))
        for index, height in enumerate(heights):
            while max_index and max_index[0][0] < height:
                i, q_index = heapq.heappop(max_index)
                res[q_index] = index
            for element in store_queries[index]:
                heapq.heappush(max_index, element)
        return res
