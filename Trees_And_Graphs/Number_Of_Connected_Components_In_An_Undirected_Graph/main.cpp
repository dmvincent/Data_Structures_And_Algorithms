#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  int count{0}, nodeCounter{0};
  int countComponents(int n, std::vector<std::vector<int>>& edges) {
    
    // Declare supporting data structures
    std::unordered_map<int,std::vector<int>> hash_map;
    std::vector<bool> seen(n);

    // Populate Hash Map
    for(auto m: edges) {
      hash_map[m[0]].push_back(m[1]);
      hash_map[m[1]].push_back(m[0]);
    }
    int curr_node;

    // Run DFS
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      curr_node = iter->first;
      if(!seen[curr_node]) {
        dfs(curr_node, hash_map, seen);
        count++;
      }
    }
    count = count + (n - nodeCounter);
    return count;
  }

  void dfs(int curr_node, std::unordered_map<int, std::vector<int>>& hash_map, std::vector<bool>& seen) {
    if(!seen[curr_node]) {
      seen[curr_node] = true;
      nodeCounter++;
      for(auto e: hash_map[curr_node]) {
        dfs(e, hash_map, seen);
      }
    }
  }
};

int main() {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0,1},{1,2},{3,4}};
  //int n = 5;
  //std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};
  Solution s1;
  int ans = s1.countComponents(n, edges);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
