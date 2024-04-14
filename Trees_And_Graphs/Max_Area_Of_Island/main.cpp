#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    void printHM(std::unordered_map<int, std::vector<int>> grid_map) {
      for(auto iter = grid_map.begin(); iter != grid_map.end(); iter++) {
        std::cout << iter->first << ": ";
        for(auto i: iter->second) {
          std::cout << i << ", ";
        }
        std::cout << std::endl;
      }
    }

    void createHashMap(std::vector<std::vector<int>>& grid, std::unordered_map<int, std::vector<int>>& grid_map, int& nodeCount, int& land) {
      // Get the Row and Column count of the input grid
      int row = grid.size();
      int col = grid[0].size();
      for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
          if(grid[i][j]) {
            land++;
            if((row <= 3 && col < 3) || (row < 3 && col <= 3)) {
              if(row <= 3 && col < 3) {
                if(row == 1 && col == 1);
                else if(row == 2 && col == 1) {
                  if(i == 0) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                  }
                }
                else if(row == 3 && col == 1) {
                  if(i == 0) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else if(i == 1) {
                    if(grid[i-1][j]) {
                      grid_map[nodeCount].push_back(nodeCount - col);
                    }
                    if(grid[i+1][j]) {
                      grid_map[nodeCount].push_back(nodeCount + col);
                    }
                  }
                  else {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                  }
                }
                else if(row == 2 && col == 2) {
                  if(i == 0 && j == 0) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 1 && j == 0) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 0 && j == 1) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                  }
                  else if(i == 1 && j == 1) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                  }
                }
                else if(row == 3 && col == 2) {
                  std::cout << "Hello" << std::endl;
                  if(i == 0 && j == 0) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 1 && j == 0) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 2 && j == 0) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 0 && j == 1) {
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                  }
                  else if(i == 1 && j == 1) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount -1);
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else if(i == 2 && j == 1) {
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                  }

                }
                else if(row == 1 && col == 2) {
                  if(i == 0 && j == 0)
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  else if(i == 0 && j == 1)
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                }
              }
              else {
                if(row == 1 && col == 3) {
                  if(i == 0 && j == 0) {
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 0 && j == 1) {
                    if(grid[i][j - 1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                  }
                  else if(i == 0 && j == 2) {
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);

                  }
                }
                else if(row == 2 && col == 3) {
                  if(i == 0 && j == 0) {
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else if(i == 0 && j == 1) {
                    if(grid[i][j - 1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else if(i == 0 && j == 2) {
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                    if(grid[i+1][j])
                      grid_map[nodeCount].push_back(nodeCount + col);
                  }
                  else if(i == 1 && j == 0) {
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                  }
                  else if(i == 1 && j == 1) {
                    if(grid[i][j - 1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                    if(grid[i][j+1])
                      grid_map[nodeCount].push_back(nodeCount + 1);
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                  }
                  else if(i == 1 && j == 2) {
                    if(grid[i][j-1])
                      grid_map[nodeCount].push_back(nodeCount - 1);
                    if(grid[i-1][j])
                      grid_map[nodeCount].push_back(nodeCount - col);
                  }
                }
              }
            }
            else {
              // Define which nodes are Up, Left, Down Right
              // Create base case for checking all non-border nodes
              if(i > 0 && i < (row-1) && j > 0 && j < (col-1)) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
              }

              // Check Non-Corner Nodes on Top Row
              else if(i == 0 && j > 0 && j < (col-1)) {
                // No upper row exists
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
              }
              // Check Non-Corner Nodes on Bottom Row
              else if(i == (row - 1) && j > 0 && j < (col-1)) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // No Lower Row Exists, Default to 0
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
              }
              // Check Non-Corner Nodes on Left Column
              else if(i > 0 && i < (row-1) && j == 0) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // No Columns to the Left, Default to 0
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
                
              }
              // Check Non-Corner Nodes on Right Column
              else if(i > 0 && i < (row-1) && j == (col-1)) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // No Columns to the right exists, default to 0
              }

              // Check top-left corner node
              else if(i == 0 && j == 0) {
                // Upper Row does not exist, defualt to 0
                // Left element does not exist, default to 0
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
              }
              // Check top-right corner node
              else if(i == 0 && j == (col - 1)) {
                // Upper Element does not exist, default to 0
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // Check Down
                if(grid[i+1][j])
                  grid_map[nodeCount].push_back(nodeCount + col);
                // Elements to the right does not exist, dault to 0;
              }
              // Check bottom-left corner node
              else if(i == (row -1) && j == 0) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // Left Element Does not exist, default to 0
                // Lower element does not exist, default to 0
                // Check Right
                if(grid[i][j+1])
                  grid_map[nodeCount].push_back(nodeCount + 1);
              }
              // Check bottom-right corner node
              else if(i == (row - 1) && j == (col - 1)) {
                // Check Up
                if(grid[i-1][j]) 
                  grid_map[nodeCount].push_back(nodeCount - col);
                // Check Left
                if(grid[i][j-1])
                  grid_map[nodeCount].push_back(nodeCount - 1);
                // Lower element does not exist, default to 0
                // Right Element does not exist, default to 0
              }
            }
          }
          nodeCount++; 
        }
      }
      
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
      // Create Hash_Map
      int nodeCount{0}, land{0};
      std::unordered_map<int,std::vector<int>> grid_map;
      createHashMap(grid, grid_map, nodeCount, land);
      printHM(grid_map);
      //std::cout << "NodeCOunt: " << nodeCount << std::endl;
      //std::cout << "Land: " << land << std::endl;
      if(land == 0) return 0;
      
      // Create seen vector and run DFS to count collections
      std::vector<int> seen(nodeCount, 0);
      int ans{0};
      for(auto iter = grid_map.begin(); iter != grid_map.end(); iter++) {
        int source = iter->first;
        if(!seen[source]) {
          int curr_max{0};
          std::cout << "Looking at: " << source << std::endl;
          dfs(grid_map, seen, iter->first, land, curr_max);
          ans = (curr_max>ans)?curr_max:ans;
        }
      }
      if(land && ans==0) return 1; // corner case where nodes are single islands
      return ans;     
    }

    void dfs(std::unordered_map<int, std::vector<int>> grid_map, std::vector<int>& seen, int source, int& land, int& curr_max) {
      if(!seen[source]) {
        seen[source] = 1;
        curr_max++;
        land--;
        for(auto e: grid_map[source]) {
          dfs(grid_map, seen, e, land, curr_max);
        }
      }
    }
};

int main() {
  //std::vector<std::vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
  //  {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},
  //  {0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
  
  //std::vector<std::vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
  //std::vector<std::vector<int>> grid{{0,0},{1,1}};
  std::vector<std::vector<int>> grid{{0,0},{0,1},{1,1}};
  Solution s1; 
  int ans = s1.maxAreaOfIsland(grid);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
