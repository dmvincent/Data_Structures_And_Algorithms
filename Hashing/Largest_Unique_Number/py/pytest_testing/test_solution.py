from solution import Solution

def test_largest_unique_number_eq1():
    nums = [5,7,3,9,4,9,8,3,1]
    expected = 8
    sol = Solution()
    assert sol.largestUniqueNumber(nums) == expected

def test_largest_unique_number_eq2():
    nums = [9,9,8,8]
    expected = -1
    sol = Solution()
    assert sol.largestUniqueNumber(nums) == expected
