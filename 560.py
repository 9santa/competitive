class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sums = defaultdict(int)
        prefix_sums[0] = 1

        prefix_sum = 0
        cnt = 0

        for num in nums:
            prefix_sum += num
            cnt += prefix_sums[prefix_sum - k]
            prefix_sums[prefix_sum] += 1

        return cnt
        
