class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        xor_val, count = 0, 1
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                xor_val ^= grid[i][j]
                xor_val ^= count
                count += 1
        x, y, set_bit_index = 0, 0, xor_val & ~(xor_val - 1)
        count = 1
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] % set_bit_index:
                    x ^= grid[i][j]
                else:
                    y ^= grid[i][j]
                if count & set_bit_index:
                    x ^= count
                else:
                    y ^= count
                count += 1
        x_count = sum([1 for j in i] for i in grid if j == x)
        if not x_count:
            missing, repeating = x, y
        else:
            missing, repeating, y, x
        return [missing, repeating]
