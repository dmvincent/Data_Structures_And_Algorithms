#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <climits>

class Solution {
public:
  void createHashMap(std::vector<std::vector<int>>& bombs, std::unordered_map<int, std::vector<int>>& hash_map) {
    for(int i = 0; i < bombs.size(); i++) {
      for(int j = i+1; j < bombs.size(); j++) {
        double d = sqrt(double(pow((bombs[i][0] - bombs[j][0]), 2) + pow((bombs[i][1] - bombs[j][1]), 2)));
        std::cout << "Node " << i << " is " << d  << " meters away from " << j << std::endl;
        if(double(bombs[i][2]) >= d) {
          hash_map[i].push_back(j);
        }
        if(double(bombs[j][2]) >= d) {
          hash_map[j].push_back(i);
        }
      }
    }
    std::cout << "================" << std::endl;
  }

  void printHashMap(std::unordered_map<int, std::vector<int>>& hash_map) {
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      std::cout << iter->first << ": ";
      for(int i = 0; i < (iter->second).size(); i++) {
        if( i == (iter->second).size() - 1)
          std::cout << (iter->second)[i] << std::endl;
        else
          std::cout << (iter->second)[i] << ", ";
      }
    }
  }

  int maximumDetonation(std::vector<std::vector<int>>& bombs) {
    // create hash map
    std::unordered_map<int, std::vector<int>> hash_map;
    createHashMap(bombs, hash_map);
    if(hash_map.size() < 1)
      return 1;

    // Print hash map for troubleshooting
    printHashMap(hash_map);
    std::cout << "=================" << std::endl;

    // Perform BFS 
    std::unordered_map<int,int> seen(bombs.size());
    std::queue<int> queue;
    int max{INT_MIN}, curr{0};
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      curr = dfs(iter->first, hash_map, seen, max);
      if(curr > max)
        max = curr;
    }
    if(curr > max)
      max = curr;

    return max;      
  }

  int dfs(int node, std::unordered_map<int, std::vector<int>>& hash_map, std::unordered_map<int, int>& seen, int& max) {
    std::cout << "Visiting node " << node << std::endl;
    int totalBombs = 0;
    if(seen.find(node) == seen.end()) {
      for(int i = 0; i < hash_map[node].size(); i++) {
        if(seen.find(hash_map[node][i]) == seen.end())
          totalBombs = totalBombs + dfs(hash_map[node][i], hash_map, seen, max);
        else
          totalBombs = totalBombs + seen[hash_map[node][i]];
      }
      seen[node] = ++totalBombs;
      if(totalBombs > max)
        max = totalBombs;
      return totalBombs;
    }
    if(seen.find(node) != seen.end()) {
      // Then you have reached the tail
      return seen[node];
    }
    return totalBombs;
  }
};

int main() {

  //std::vector<std::vector<int>> bombs{{2,1,3},{6,1,4}};
  //std::vector<std::vector<int>> bombs{{1,1,5},{10,10,5}};
  std::vector<std::vector<int>> bombs{{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};

  for(int i = 0; i < bombs.size(); i++) {
    std::cout << "Radius for node " << i << " is " << bombs[i][2] << std::endl;
  }
  std::cout << "===============" << std::endl;
  Solution s1;
  int ans = s1.maximumDetonation(bombs);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
