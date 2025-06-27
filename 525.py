class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        arr = [1 if x == 1 else -1 for x in nums]
        prefix_sum_indices = {0: -1}
        prefix_sum = 0
        max_len = 0

        for i in range(0, len(nums)):
            prefix_sum += arr[i]

            if prefix_sum in prefix_sum_indices:
                max_len = max(max_len, i - prefix_sum_indices[prefix_sum])

            else:
                prefix_sum_indices[prefix_sum] = i

        return max_len
                    
