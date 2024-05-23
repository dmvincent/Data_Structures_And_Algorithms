from typing import List

def test_a1():
    nums = [7,4,3,9,1,8,5,2,6]
    k = 3
    sol = Solution()
    assert sol.getAverages(nums, k) == [-1,-1,-1,5,4,4,-1,-1,-1]

class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        currSum = 0
        if k == 0:
            return nums

        if len(nums) < 2*k + 1:
            return [-1] * len(nums)

        ans = [0] * len(nums)
        for i in range(k):
            ans[i] = -1
            currSum += nums[i]

        for i in range(k, 2*k + 1):
            currSum += nums[i]

        ans[k] = currSum//(2*k+1)
        
        for i in range(len(nums) - k, len(nums)):
            ans[i] = -1

        for i in range(2*k + 1, len(nums)):
            currSum = currSum - nums[i - 2*k - 1] + nums[i]
            ans[i - k] = currSum // (2*k + 1)

        return ans

if __name__ == "__main__":
    nums = [7,4,3,9,1,8,5,2,6]
    k = 3

    #nums = [1000]
    #k = 0

    #nums = [8]
    #k = 1000

    sol = Solution()
    ans = sol.getAverages(nums, k)

    for i in ans:
        print(i)

