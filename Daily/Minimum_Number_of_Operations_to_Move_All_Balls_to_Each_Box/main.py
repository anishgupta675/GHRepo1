class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        ans = [0] * len(boxes)
        b1, m1, b2, m2 = 0, 0, 0, 0
        for i in range(len(boxes)):
            ans[i] += m1
            b1 += int(boxes[i])
            m1 += b1
            ans[len(boxes) - 1 - i] += m2
            b2 += int(boxes[len(boxes) - 1 - i])
            m2 += b2
        return ans
