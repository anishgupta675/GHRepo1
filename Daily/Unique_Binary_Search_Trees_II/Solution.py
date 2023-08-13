from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> list[Optional[TreeNode]]:
        def generate(low, high) -> list[Optional[TreeNode]]:
            if low > high:
                return [None]
            if low == high:
                return [TreeNode(low)]
            res = []
            for i in range(low, high + 1):
                for j in range(low, i - 1):
                    for k in range(i + 1, high):
                        root = TreeNode(i, j, k)
                        res.append(root)
            return res
        return generate(1, n)