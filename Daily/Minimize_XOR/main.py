class Solution:
    def checkBit(self, x: int, bit: int) -> bool:
        return x & (1 << bit)
    def setBit(self, x: int, bit: int):
        return x | (1 << bit)
    def unsetBit(self, x: int, bit: int):
        return x & ~(1 << bit)
    def minimizeXor(self, num1: int, num2: int) -> int:
        res = num1
        count1, count2, curr = bin(num2).count("1"), bin(res).count("1"), 0
        while count2 < count1:
            if not self.checkBit(res, curr):
                res += self.setBit(res, curr)
                count2 += 1
            curr += 1
        while count2 > count1:
            if self.checkBit(res, curr):
                res = self.unsetBit(res, curr)
                count2 -= 1
            curr += 1
        return res
