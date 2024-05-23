from typing import List

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        curr = 0
        ans = 0
        for i in range(len(nums)):
            curr += nums[i]
            if curr < 1:
                ans = ans + 1 - curr
                curr = 1

        if ans == 0:
            ans = 1
        return ans

if __name__ == "__main__":
    #nums = [-3,2,-3,4,2]
    #nums = [1,2]
    #nums = [1,-2,-3]
    nums = [2,3,5,-5,-1]

    obj = Solution()
    ans = obj.minStartValue(nums)
    print(ans)
