from solution import Solution

def test_missinNumber_e1():
    nums = [3,0,1]
    sol = Solution()
    assert sol.missingNumber(nums) == 2

def test_missinNumber_e2():
    nums = [0,1]
    sol = Solution()
    assert sol.missingNumber(nums) == 2
