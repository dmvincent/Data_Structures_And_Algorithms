from solution import Solution
def test_solutionA() :
    sentence = "thequickbrownfoxjumpsoverthelazydog"
    sol = Solution()
    assert sol.checkIfPangram(sentence) == True
