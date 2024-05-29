from solution import Solution
import pytest

@pytest.fixture()
def setupFindMaxLength() -> Solution:
    sol = Solution()
    return sol

testCases = [[0,1], [0,1,0],[0,0,0,1,1,1,0]]
expectedResults = [2,2,3]

cases = zip(testCases, expectedResults)
@pytest.mark.hashing
@pytest.mark.parametrize("case", cases)
def test_findMaxLength_eq(setupFindMaxLength, case):
    assert case[1] == setupFindMaxLength.findMaxLength(case[0])
