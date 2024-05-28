from solution import Solution
import pytest

class Test_Max_Number_Of_Balloons:
    @pytest.mark.standardCase
    def test_getMax(self):
        sol = Solution()
        userInput = "nlaebolko"
        expected = 1
        result = sol.maxNumberOfBalloons(userInput)
        assert expected == result
        
    @pytest.mark.standardCase
    def test_getMax_e2(self):
        sol = Solution()
        userInput = "loonbalxballpoon"
        expected = 2
        result = sol.maxNumberOfBalloons(userInput)
        assert expected == result

    @pytest.mark.edgeCase1
    def test_getMax_e3(self):
        sol = Solution()
        userInput = "leetcode"
        expected = 0
        result = sol.maxNumberOfBalloons(userInput)
        assert expected == result

