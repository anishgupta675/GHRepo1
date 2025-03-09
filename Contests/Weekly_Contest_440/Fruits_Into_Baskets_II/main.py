class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n, count, placed_fruits, placed_baskets = len(fruits), 0, set(), set()
        for i in range(len(fruits)):
            for j in range(len(baskets)):
                if fruits[i] <= baskets[j] and i not in placed_fruits and j not in placed_baskets:
                    placed_fruits.add(i)
                    placed_baskets.add(j)
                    count += 1
        return n - len(placed_fruits)
