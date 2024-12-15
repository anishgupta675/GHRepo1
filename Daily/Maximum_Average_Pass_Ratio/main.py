class Solution:
    def maxAverageRatio(self, classes: List[List[int]], k: int) -> float:
        n, total, a = len(classes), 0, []
        for p,q in classes:
            total += p / q
            a.append(((p - q) / (q * (q + 1)), p, q))
        heapify(a)
        for i in range(k):
            r, p, q = a[0]
            if not r:
                break
            total -= r
            r2 = (p - q) / ((q + 1.0) * (q + 2.0))
            heapreplace(a, (r2, p + 1, q + 1))
        return total / n
