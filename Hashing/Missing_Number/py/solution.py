from typing import List
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        hashMap = set(nums)
        for i in range(len(nums) + 1):
            if i not in hashMap:
                return i

        return -1
