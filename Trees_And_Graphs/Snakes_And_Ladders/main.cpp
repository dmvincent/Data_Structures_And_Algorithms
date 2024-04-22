#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Solution {
public:

  // Helper function to get node indices from node position
  std::vector<int> getNodeIndices(int nodePos, int n) {
    std::vector<int> matrixPos(2);
    int row, col;

    // Get the row
    if(nodePos%n == 0)
      row = n - (nodePos/n);
    else
      row = (n-1) - (nodePos/n);

    // Get Column
    if((n - row) % 2) {
      if(nodePos%n == 0)
        col = n-1;
      else
        col = (nodePos % n) - 1;
    }
    else {
      if(nodePos%n == 0)
        col = 0;
      else
        col = (n - 1) - ((nodePos%n) - 1);
    }

    matrixPos[0] = row;
    matrixPos[1] = col;
    return matrixPos;
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
    int curr_steps{0};
    int curr{0};

    while(!queue.empty()) {
      state = queue.front();
      curr = state[0];
      curr_steps = state[1];
      if(curr == n*n)
        return curr_steps;
      queue.pop();
      for(int i = curr + 1; i <= std::min(curr + 6, n*n); i++) {
        nodeLoc = getNodeIndices(i, n);
        
        // Determine if nodeLoc has a Snake or Ladder
        if(board[nodeLoc[0]][nodeLoc[1]] != -1) {
          addNode[0] = board[nodeLoc[0]][nodeLoc[1]];
          addNode[1] = curr_steps + 1;
        }
        else {
          addNode[0] = i;
          addNode[1] = curr_steps + 1;
        }

        if(set.find(addNode[0]) == set.end()) {
          queue.push(addNode);
          set.insert(addNode[0]);
        }
      }
    }

    return -1;
  }
};

int main() {
  //std::vector<std::vector<int>> board {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
  std::vector<std::vector<int>> board {{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}};
  Solution s1;
  int ans = s1.snakesAndLadders(board);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
