#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

void printHash(std::unordered_map<int, std::set<int>>& hash_map) {
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      std::cout << iter->first << ": {";
      for(auto setIter = (iter->second).begin(); setIter != (iter->second).end(); setIter++) {
        std::cout << *setIter << ", "; 
      }
      std::cout << "}" << std::endl;
    }
}

class Solution {
public:
  std::unordered_map<int, std::vector<int>> hash_map;
  
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    if(n==1) return true;
    std::vector<bool> seen(n);
    // Pre-Process Hash Map
    for(auto m: edges) {
      hash_map[m[0]].push_back(m[1]);
      hash_map[m[1]].push_back(m[0]);
    }
    
    // Call DFS
    return dfs(source, destination, seen);
  }
  
  bool dfs(int source, int destination, std::vector<bool>& seen) {
    if(source == destination) return true;
    if(!seen[source]) {
      seen[source] = true;
        for(auto iter: hash_map[source]) {
          source = iter;
          if(dfs(source, destination, seen))
            return true;
        }
    }
    return false;
  }
};

int main() {
  //std::vector<std::vector<int>> edges{{0,1},{1,2},{2,0}};
  //int n{3}, source{0}, destination{2};

  //std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
  //int n{6}, source{0}, destination{5};

  std::vector<std::vector<int>> edges = {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
  int n{10}, source{7}, destination{5};

  Solution s1;
  bool ans = s1.validPath(n, edges, source, destination);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
