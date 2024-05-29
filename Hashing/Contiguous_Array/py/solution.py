from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        start, end = 0, 0
        currSum = 0
        count = 0
        ans = 0
        while end < len(nums):
            currSum += nums[end]
            end += 1
            if((len(nums) % 2 == 1) and len(nums) == end):
                currSum -= nums[start]
                start += 1
                count = end - start
                ans = max(ans,count)
                return ans

            currSum += nums[end]
            count = end - start + 1
            ans = max(ans, count)
            if currSum != (end//2 + 1):
                start = end
                currSum = 0
            end += 1

        return ans

if __name__ == "__main__":
    #nums = [0,1]
    nums = [0,1,0]
    sol = Solution()
    print("Anser:", sol.findMaxLength(nums))
