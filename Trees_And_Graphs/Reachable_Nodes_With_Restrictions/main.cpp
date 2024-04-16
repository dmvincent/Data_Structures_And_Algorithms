#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
  void createHashMap(std::unordered_map<int, std::vector<int>>& hash_map, std::set<int> restricted, std::vector<std::vector<int>> edges) {
    for(auto n: edges) {
      if(restricted.find(n[0]) != restricted.end() || restricted.find(n[1]) != restricted.end()) 
        continue;
      hash_map[n[0]].push_back(n[1]);
      hash_map[n[1]].push_back(n[0]);
    }

  }
  
  void dfs(std::unordered_map<int, std::vector<int>> hash_map, std::vector<int>& seen, int source, int& ans) {
    if(!seen[source]) {
      seen[source] = 1;
      ans++;
      for(auto n: hash_map[source]) {
        dfs(hash_map, seen, n, ans);
      }
    }
  }


  int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted) {
    //Create Hash Map using vector 'seen' 'restricted' to manage hash map creation
    std::unordered_map<int, std::vector<int>> hash_map;
    std::set<int> noGoZones(restricted.begin(), restricted.end());
    createHashMap(hash_map, noGoZones, edges);

    // Run DFS incremeint count variable to each node reached from 0
    std::vector<int> seen(n, 0);
    int ans{0};
    dfs(hash_map, seen, 0, ans);
    return ans;
  }
};

int main() {
  // Provide Input
  int n{7};
  std::vector<std::vector<int>> edges{{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
  std::vector<int> restricted{4,5};

  //int n{4};
  //std::vector<std::vector<int>> edges{{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
  //std::vector<int> restricted{1,2,4};

  // Call method
  Solution s1;
  int ans = s1.reachableNodes(n, edges, restricted);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
