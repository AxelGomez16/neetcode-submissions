class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        streak_1 = 0
        streak_max = 0

        for i in nums:
            if i == 1:
                streak_1 += 1
            else:
                streak_max = max(streak_1, streak_max)
                streak_1 = 0

        return max(streak_1, streak_max)
