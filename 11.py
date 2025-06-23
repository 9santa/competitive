from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1 # tuple unpacking (multiple assignment)
        maxA = 0

        while l < r:
            current_area = min(height[l], height[r]) * (r - l)
            maxA = max(maxA, current_area)

            if height[l] < height[r]: l+= 1
            else: r -= 1

        return maxA
        
if __name__ == "__main__":
    sol = Solution()
    height = [1,8,6,2,5,4,8,3,7]

    print(sol.maxArea(height))
