class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        pref = [0] * len(A)
        for i in range(len(A)):
            for j in range(i + 1):
                for k in range(i + 1):
                    if A[j] == B[k]:
                        pref[i] += 1
                        break
        return pref
