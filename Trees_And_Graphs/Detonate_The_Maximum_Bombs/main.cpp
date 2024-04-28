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
        //std::cout << "Node " << i << " is " << d  << " meters away from " << j << std::endl;
        if(double(bombs[i][2]) >= d) {
          hash_map[i].push_back(j);
        }
        if(double(bombs[j][2]) >= d) {
          hash_map[j].push_back(i);
        }
      }
    }
    //std::cout << "================" << std::endl;
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
    std::set<int> seen;
    int size = bombs.size();
    std::vector<int> chain(bombs.size(), 0);
    int max{INT_MIN}, curr{0};
    for(int i = 0; i < bombs.size(); i++) {
      if(seen.find(i) == seen.end()) {
        seen.insert(i);
        curr = dfs(i, hash_map, max, seen, chain, size);
        seen.clear();
        max = std::max(max, curr);
      }
      else {
        max = std::max(max, chain[i]);
      }
    }
    
    return max;      
  }

  int dfs(int node, std::unordered_map<int, std::vector<int>>& hash_map, int& max, std::set<int>& seen, std::vector<int>& chain, int& size) {
    std::cout << "Visiting node " << node << std::endl;
    int curr = 0;

    for(int i = 0; i < hash_map[node].size(); i++) {
      if(seen.find(hash_map[node][i]) != seen.end()) {
        //chain[node] += chain[hash_map[node][i]];
      } else {
        seen.insert(hash_map[node][i]);
        curr =  curr + dfs(hash_map[node][i], hash_map, max, seen, chain, size);
      }
    }
    curr = curr + 1;
    //chain[node] += curr;

    return curr;
  }
};

int main() {

  //std::vector<std::vector<int>> bombs{{2,1,3},{6,1,4}};
  //std::vector<std::vector<int>> bombs{{1,1,5},{10,10,5}};
  //std::vector<std::vector<int>> bombs{{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
  std::vector<std::vector<int>> bombs{{56,80,2},{55,9,10},{32,75,2},{87,89,1},{61,94,3},{43,82,9},{17,100,6},{50,6,7},{9,66,7},{98,3,6},{67,50,2},{79,39,5},{92,60,10},{49,9,9},{42,32,10}};
  //std::vector<std::vector<int>> bombs{{868,658,84},{82,386,48},{464,157,11},{422,654,85},{864,418,84},{366,314,72},{955,270,60},{460,98,60},{824,147,38},{580,660,27},{423,102,73},{317,471,74}};

  Solution s1;
  int ans = s1.maximumDetonation(bombs);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
