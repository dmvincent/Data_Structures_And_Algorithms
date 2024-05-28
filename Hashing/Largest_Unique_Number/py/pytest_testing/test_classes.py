from solution import Solution
import pytest



class Test_Largest_Unique_Number:
    @pytest.mark.classesTest
    def test_a1(self):
        nums = [5,7,3,9,4,9,8,3,1]
        expected = 8
        sol = Solution()
        assert sol.largestUniqueNumber(nums) == expected

