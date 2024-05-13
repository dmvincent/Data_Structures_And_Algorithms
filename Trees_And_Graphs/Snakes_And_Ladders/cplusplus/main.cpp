#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Solution {
public:

  // Helper function to get node indices from node position
  void getNodeIndices(int nodePos, int n, std::vector<int>& matrixPos) {
    // Get the row
    if(nodePos%n == 0)
      matrixPos[0] = n - (nodePos/n);
    else
      matrixPos[0] = (n-1) - (nodePos/n);

    // Get Column
    if((n - matrixPos[0]) % 2) {
      if(nodePos%n == 0)
        matrixPos[1] = n-1;
      else
        matrixPos[1] = (nodePos % n) - 1;
    }
    else {
      if(nodePos%n == 0)
        matrixPos[1] = 0;
      else
        matrixPos[1] = (n - 1) - ((nodePos%n) - 1);
    }

  }

  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    int n = board.size();            // Number of rows and columns in 'board'
    // Start a queue, insert the first state, and start BFS
    std::vector<int> startState{1, 0}; // {nodeNumber, steps}
    std::queue<std::vector<int>> queue; // [row, col, steps, snake or ladder or none]
    queue.push(startState);

    std::vector<int> addNode(2);
    std::vector<int> nodeLoc(2);
    std::vector<int> state(2);
    std::set<int> set;

    while(!queue.empty()) {
      state = queue.front();
      if(state[0] == n*n)
        return state[1];
      queue.pop();
      for(int i = state[0] + 1; i <= std::min(state[0] + 6, n*n); i++) {
        if(set.find(i) == set.end()) {
          set.insert(i);
          getNodeIndices(i, n, nodeLoc);
          // Determine if nodeLoc has a Snake or Ladder
          if(board[nodeLoc[0]][nodeLoc[1]] != -1) {
            addNode[0] = board[nodeLoc[0]][nodeLoc[1]];
            addNode[1] = state[1] + 1;
          }
          else {
            addNode[0] = i;
            addNode[1] = state[1] + 1;
          }
          queue.push(addNode);
        }
      }
    }
    return -1;
  }
};

int main() {
  std::vector<std::vector<int>> board {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
  //std::vector<std::vector<int>> board {{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}};
  Solution s1;
  int ans = s1.snakesAndLadders(board);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
