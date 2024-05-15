#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> ans;     
    std::vector<int> curr = {0};
    for(auto& i: graph[0]) {
      curr.push_back(i);
      backtrack(graph, curr, ans, i); 
      curr.pop_back();
    }
    return ans;
  }

  void backtrack(std::vector<std::vector<int>>& graph, std::vector<int>& curr, std::vector<std::vector<int>>& ans, int& i) {
    if(curr[curr.size() - 1] == graph.size() - 1) {
      ans.push_back(curr);
      return;
    }

    for(auto& j: graph[i]) {
      curr.push_back(j);
      backtrack(graph, curr, ans, j);
      curr.pop_back();
    }

  }

};

int main() {
  //std::vector<std::vector<int>> graph{{1,2},{3},{3},{}};
  std::vector<std::vector<int>> graph{{4,3,1},{3,2,4},{3},{4},{}};
  
  Solution s1;
  std::vector<std::vector<int>> ans = s1.allPathsSourceTarget(graph);

  std::cout << "Answer: " << std::endl << "======================" << std::endl;
  for(int i = 0; i < ans.size(); i++) {
    std::cout << "[";
    for(int j = 0; j < ans[i].size(); j++) {
      std::cout << ans[i][j] << ", ";
    }
    std::cout << "]" << std::endl;
  }
  return 0;
}
