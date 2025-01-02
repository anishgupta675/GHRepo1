class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        total, prefix_sum, vowels, ans = 0, [0] * len(words), {"a", "e", "i", "o", "u"}, [0] * len(queries)
        for i in range(len(words)):
            if words[i][0] in vowels and words[i][len(words[i]) - 1] in vowels:
                total += 1
            prefix_sum[i] = total
        for i in range(len(queries)):
            ans[i] = prefix_sum[queries[i][1]] - (0 if not queries[i][0] else prefix_sum[queries[i][0] - 1])
        return ans
