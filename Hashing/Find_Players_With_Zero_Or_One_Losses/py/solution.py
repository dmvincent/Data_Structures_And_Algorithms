from typing import List

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losers = {}
        undefeated = set()

        for winner, loser in matches:
            if winner not in losers:
                undefeated.add(winner)
            
            if loser in undefeated:
                undefeated.remove(loser)

            if loser not in losers:
                losers[loser] = 1
            else:
                losers[loser] += 1

        one_loss = [] 
        for key, val in losers.items():
            if val == 1:
                one_loss.append(key)

        return [sorted(undefeated),sorted(one_loss)]

if __name__ == "__main__":
    matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]

    sol = Solution()
    ans = sol.findWinners(matches)
