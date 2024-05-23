from solution import Solution

def test_find_players_with_zero_or_one_losses_e1():
    matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    sol = Solution()
    assert sol.findWinners(matches) == [[1,2,10],[4,5,7,8]]
