class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        diff = [0] * len(s)
        for i in shifts:
            if i[2] == 1:
                diff[i[0]] += 1
                if i[1] + 1 < len(s):
                    diff[i[1] + 1] -= 1
            else:
                diff[i[0]] -= 1
                if i[1] + 1 < len(s):
                    diff[i[1] + 1] += 1
        res = list(s)
        count = 0
        for i in range(len(s)):
            count = (count + diff[i]) % 26
            if count < 0:
                count += 26
            char = chr((ord(s[i]) - ord("a") + count) % 26 + ord("a"))
            res[i] = char
        return "".join(res)
