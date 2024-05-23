from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            nums[i] = nums[i-1] + nums[i]
        return nums

if __name__ == "__main__":
    print("hello")
    s1 = Solution()
    nums = [1,2,3,4]
    ans = s1.runningSum(nums);
    for i in range(len(nums)):
        print(nums[i])
