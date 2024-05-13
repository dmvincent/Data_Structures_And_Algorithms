from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        place = len(nums) - 1
        ans = [0] * len(nums)
        while left <= right:
            if abs(nums[left]) > nums[right]:
                ans[place] = nums[left]**2
                left+=1
            else:
                ans[place] = nums[right]**2
                right-=1
            place -=1
        return ans



if __name__ == "__main__":
    nums = [-4,-1,0,3,10]
    #nums = [-7,-3,2,3,11]
    sol = Solution()
    arr = sol.sortedSquares(nums)

