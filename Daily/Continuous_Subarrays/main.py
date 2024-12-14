class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        right, left, cur_min, cur_max, win_length, ans = 0, 0, sys.maxsize, sys.maxsize * -1, 0, 0
        while right < len(nums):
            cur_min = min(cur_min, nums[right])
            cur_max = max(cur_max, nums[right])
            if cur_max - cur_min > 2:
                win_length = right - left
                ans += win_length * (win_length + 1) // 2
                left = right
                cur_min = cur_max = nums[right]
                while left > 0 and abs(nums[right] - nums[left - 1]) <= 2:
                    left -= 1
                    cur_min = min(cur_min, nums[left])
                    cur_max = max(cur_max, nums[left])
                if left < right:
                    win_length = right - left
                    ans -= win_length * (win_length + 1) // 2
            right += 1
        win_length = right - left
        ans += win_length * (win_length + 1) // 2
        return ans
