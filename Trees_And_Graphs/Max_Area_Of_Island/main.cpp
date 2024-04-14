#include <iostream>
#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
      // Get the Row and Column count of the input grid
      int row = grid.size();
      int col = grid[0].size();
      //std::cout << "Number of rows: " << row << std::endl;
      //std::cout << "Number of columns: " << col << std::endl;

      // Map the edges
      std::vector<std::vector<std::vector<int>>> grid_map(row, std::vector<std::vector<int>>(col, std::vector<int>(4, 0)));
      //int rowB = grid_map.size();
      //int colB = grid_map[0].size();
      //int num = grid_map[0][0].size();
      //std::cout << "Number of rows: " << rowB << std::endl;
      //std::cout << "Number of columns: " << colB << std::endl;
      //std::cout << "Number of num: " << num << std::endl;
      int i{0}, j{0};
      for(auto m: grid) {
        for(auto n: m) {
          // Create base case for checking all non-border nodes
          if(i > 0 && i < (row-1) && j > 0 && j < (col-1)) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][2] = 1;
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
          }

          // Check Non-Corner Nodes on Top Row
          else if(i == 0 && j > 0 && j < (col-1)) {
            // No upper row exists
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][2] = 1;
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
          }
          // Check Non-Corner Nodes on Bottom Row
          else if(i == (row - 1) && j > 0 && j < (col-1)) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // No Lower Row Exists, Default to 0
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
          }
          // Check Non-Corner Nodes on Left Column
          else if(i > 0 && i < (row-1) && j == 0) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // No Columns to the Left, Default to 0
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][2] = 1;
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
            
          }
          // Check Non-Corner Nodes on Right Column
          else if(i > 0 && i < (row-1) && j == (col-1)) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][2] = 1;
            // No Columns to the right exists, default to 0
          }

          // Check top-left corner node
          else if(i == 0 && j == 0) {
            // Upper Row does not exist, defualt to 0
            // Left element does not exist, default to 0
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][2] = 1;
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
          }
          // Check top-right corner node
          else if(i == 0 && j == (col - 1)) {
            // Upper Element does not exist, default to 0
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // Check Right
            // Check Down
            if(grid[i+1][j])
              grid_map[i][j][3] = 1;
            // Check Right
            // Elements to the right does not exist, dault to 0;
          }
          // Check bottom-left corner node
          else if(i == (row -1) && j == 0) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // Left Element Does not exist, default to 0
            // Lower element does not exist, default to 0
            // Check Right
            if(grid[i][j+1])
              grid_map[i][j][3] = 1;
          }
          // Check bottom-right corner node
          else if(i == (row - 1) && j == (col - 1)) {
            // Check Up
            if(grid[i-1][j]) 
              grid_map[i][j][0] = 1;
            // Check Left
            if(grid[i][j-1])
              grid_map[i][j][1] = 1;
            // Lower element does not exist, default to 0
            // Right Element does not exist, default to 0
          }
 
          j++;
        }
        i++;
      }
      return 0;     
    }
};

int main() {
  std::vector<std::vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
  Solution s1; 
  int ans = s1.maxAreaOfIsland(grid);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
