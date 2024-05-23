from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        right, left = 0, 0
        ans = 0 
        zLoc = []
        i = 0
        while right < len(nums):
            if nums[right] == 0:
                zLoc.append(right)
                k -= 1

            if k == -1:
                left = zLoc[i] + 1
                i += 1
                k = 0

            ans = max(ans, right-left+1)

            right += 1

        return ans

if __name__ == "__main__":
    #nums = [1,1,1,0,0,0,1,1,1,1,0]
    #k = 2

    nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    k = 3

    s1 = Solution()
    ans = s1.longestOnes(nums, k)
    print(ans)
