# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def count_swaps(nums):
            swaps, sorted_nums, index_map = 0, sorted(nums), {n:i for i, n in enumerate(nums)}
            for j in range(len(nums)):
                if nums[j] != sorted_nums[j]:
                    swaps += 1
                    k = index_map[sorted_nums[j]]
                    nums[j], nums[k] = nums[k], nums[j]
                    index_map[nums[j]] = j
                    index_map[nums[k]] = k
            return swaps
        q, res = deque([root]), 0
        while q:
            level = []
            for i in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res += count_swaps(level)
        return res
