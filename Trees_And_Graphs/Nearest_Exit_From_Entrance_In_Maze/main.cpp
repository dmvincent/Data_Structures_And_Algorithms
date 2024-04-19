#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Solution {
public:
  bool validStep(int row, int col, int rowLength, int colLength, std::vector<std::vector<char>>& maze, std::set<std::vector<int>>& seen) {
    if(row >= 0 && row < rowLength && col >= 0 && col < colLength && maze[row][col] == '.' && seen.find({row,col}) == seen.end())
      return true;
    return false;
  }
  
  bool onBorder(std::vector<int>& node, std::vector<int>& entrance, int rowLength, int colLength) {
    if(node[0] == 0 || node[0] == (rowLength-1) || node[1] == 0 || node[1] == (colLength - 1)) {
      //std::cout << "{" << node[0] << ", " << node[1] << "} True" << std::endl;
      return true;
    }
    else {
      //std::cout << "{" << node[0] << ", " << node[1] << "} False" << std::endl;
      return false;
    }
  }

  int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
    int steps{0};      
    int rowLength = maze.size();
    int colLength = maze[0].size();
    std::vector<std::vector<int>> directions{{-1,0}, {0,1}, {1,0}, {0,-1}};
    std::queue<std::vector<int>> queue;
    std::set<std::vector<int>> seen;

    // Iterate over each level for every while loop
    queue.push(entrance);
    seen.insert(entrance);
    while(!queue.empty()) {
      std::vector<int> node = queue.front();
      queue.pop();
      if(onBorder(node, entrance, rowLength, colLength) && node != entrance)
        return steps;
      std::cout << "=====================" << std::endl;
      for(auto d: directions) {
        int row = node[0] + d[0];
        int col = node[1] + d[1];
        if(validStep(row, col, rowLength, colLength, maze, seen)) {
          std::cout << "Pushing: {" << row << ", " << col << "}" << std::endl;
          queue.push({row,col});
          seen.insert({row,col});
        }
      }
      steps++;
    }
    return -1;        
  }
};

int main() {
  // std::vector<std::vector<char>> maze {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
  // std::vector<int> entrance {1,2};
  //std::vector<std::vector<char>> maze {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
  //std::vector<int> entrance {1,0};
  //std::vector<std::vector<char>> maze{{'.','+'}};
  //std::vector<int> entrance{0,0};
  //std::vector<std::vector<char>> maze  {{'.','+','+','+','+'},{'.','+','.','.','.'},{'.','+','.','+','.'},{'.','.','.','+','.'},{'+','+','+','+','.'}};
  //std::vector<int> entrance {0,0};
  std::vector<std::vector<char>> maze {{'+','.','+','+','+','+','+'},{'+','.','+','.','.','.','+'},{'+','.','+','.','+','.','+'},{'+','.','.','.','.','.','+'},{'+','+','+','+','.','+','.'}};
  std::vector<int> entrance{0,1};
  Solution s1;
  int ans = s1.nearestExit(maze, entrance);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
