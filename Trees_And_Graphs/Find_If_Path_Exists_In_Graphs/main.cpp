#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
  std::set<int> seen;
  std::unordered_map<int, std::vector<int>> hash_map;
  
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    // Pre-Process Hash Map
    for(auto m: edges) {
      hash_map[m[0]].push_back(m[1]);
      hash_map[m[1]].push_back(m[0]);
    }
    
    // Call DFS
    return dfs(source, destination);
  }
  
  bool dfs(int source, int destination) {
    //if(hash_map[source] == destination)
    //  return false;

    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      std::cout << iter->first << ": ";
      for(auto i: iter->second)
        std::cout << i << ", ";
      std::cout << std::endl;
    } 
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> edges{{0,1},{1,2},{2,0}};
  int n{3}, source{0}, destination{2};

  //std::vector<int> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
  //int n{6}, source{0}, destination{5};

  Solution s1;
  bool ans = s1.validPath(n, edges, source, destination);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
