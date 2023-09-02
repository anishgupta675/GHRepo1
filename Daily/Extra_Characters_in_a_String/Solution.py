# class Trie:
#     words = {}
#     flag = False
#     def insert(self, word: str, idx: int):
#         if not word:
#             flag = True
#             return
#         if not self.words[word[idx] - 'a']:
#             self.words[word[idx] - 'a'] = Trie()
#         self.words[word[idx] - 'a'].insert(word, idx + 1)
#     def contains(self, word: str, idx: int) -> bool:
#         if not word:
#             return True
#         if idx == len(word):
#             return self.flag
#         if not self.words[word[idx] - 'a']:
#             return False
#         return self.words[word[idx] - 'a'].contains(word, idx + 1)
class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False
class Trie:
    def __init__(self, words):
        self.root = TrieNode()
        for w in words:
            curr = self.root
            for c in w:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]
            curr.word = True
class Solution:
    def minExtraChar(self, s: str, dictionary: list[str]) -> int:
        dp = { len(s): 0 }
        trie = Trie(dictionary).root
        def dfs(i):
            if i in dp:
                return dp[i]
            res = 1 + dfs(i + 1)
            curr = trie
            for j in range(i, len(s)):
                if s[j] not in curr.children:
                    break
                curr = curr.children[s[j]]
                if curr.word:
                    res = min(res, dfs(j + 1))
            dp[i] = res
            return res
        return dfs(0)