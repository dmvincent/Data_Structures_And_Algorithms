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
      int rowUpper{0}, rowLower{0}, colLeft{0}, colRight{0};
      rowLower = row-1;
      colRight = col -1;
      for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
          if(grid[i][j]) {
            land++;
            // Check Upper
            if((i-1) >= rowUpper) {
              if(grid[i-1][j])
                grid_map[nodeCount].push_back(nodeCount - col);
            }
            // Check Left
            if((j-1) >= colLeft) {
              if(grid[i][j-1])
                grid_map[nodeCount].push_back(nodeCount - 1);

            }
            
            // Check Down
            if((i+1) <= rowLower) {
              if(grid[i+1][j])
                grid_map[nodeCount].push_back(nodeCount + col);
            }
            
            // Check Right
            if((j+1) <= colRight) {
              if(grid[i][j+1])
                grid_map[nodeCount].push_back(nodeCount + 1);
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
      //printHM(grid_map);
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
          //std::cout << "Looking at: " << source << std::endl;
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
