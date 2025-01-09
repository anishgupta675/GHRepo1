class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        f = 0
        for i in range(len(words)):
            if words[i].startswith(pref):
                f += 1
        return f
