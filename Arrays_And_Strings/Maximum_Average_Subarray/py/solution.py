from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        currSum = 0
        for i in range(k):
            currSum+=nums[i]
        right = k
        ans = currSum
        while right < len(nums):
            currSum+=nums[right]
            currSum-=nums[right-k]
            ans = max(ans, currSum)
            right+=1

        return ans/k

if __name__ == "__main__":
    nums = [1,12,-5,-6,50,3]
    k = 4

    obj = Solution()
    ans = obj.findMaxAverage(nums, k)
    print("Answer:", ans)
