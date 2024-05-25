from typing import List
from collections import defaultdict

class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        hash_map = defaultdict(int)
        for num in nums:
            hash_map[num] += 1
        
        ans = -1
        for key, val in hash_map.items():
            if val == 1:
                ans = max(ans, key)

        return ans

if __name__ == "__main__":
    nums = [5,7,3,9,4,9,8,3,1]

    sol = Solution()
    print(sol.largestUniqueNumber(nums))
