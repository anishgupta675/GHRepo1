class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2:
            return False
        b1, b2 = [], []
        for i in range(len(s)):
            if locked[i] == "0":
                b2.append(i)
            elif s[i] == "(":
                b1.append(i)
            elif s[i] ==")":
                if b1:
                    b1.pop(len(b1) - 1)
                elif b2:
                    b2.pop(len(b2) - 1)
                else:
                    return False
        while b1 and b2 and b1[-1] < b2[-1]:
            b1.pop(len(b1) - 1)
            b2.pop(len(b2) - 1)
        if b1:
            return False
        return True
