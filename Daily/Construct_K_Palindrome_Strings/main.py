class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        if len(s) == k:
            return True
        odd = 0
        for i in s:
            odd ^= 1 << (ord(i) - ord("a"))
        return bin(odd).count("1") <= k
