class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        nums.sort()

        for i in range(n-2):
            if i > 0 and nums[i] == nums[i-1]: continue
            l, r = i + 1, n - 1
            while l < r:
                sum3 = nums[i] + nums[l] + nums[r]
                if sum3 == 0:
                    ans.append([nums[i], nums[l], nums[r]])

                    while(l < r and nums[l] == nums[l+1]): l += 1
                    while(r > l and nums[r] == nums[r-1]): r -= 1

                    l += 1
                    r -= 1

                if sum3 < 0:
                    l += 1
                elif sum3 > 0:
                    r -= 1

        return ans
