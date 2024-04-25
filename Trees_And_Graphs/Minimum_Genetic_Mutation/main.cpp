#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
    // Create the Hash Map
    std::unordered_map<std::string, std::vector<std::string>> hash_map;
    for(int i = 0; i < bank.size(); i++) {
      for(int j = i + 1; j < bank.size(); j++) {
        int count = 0;
        for(int q = 0; q != bank[0].size(); q++) {
          if(bank[i][q] != bank[j][q]) {
            count++;
          }
        }
        if(count == 1) {
          hash_map[bank[i]].push_back(bank[j]);
          hash_map[bank[j]].push_back(bank[i]);
        }
      }
      
      // Include startGene in the hash map
      int count = 0;
      for(int q = 0; q != bank[0].size(); q++) {
        if(bank[i][q] != startGene[q]) {
            count++;
        }
        
      }
      if(count == 1) {
        hash_map[bank[i]].push_back(startGene);
        hash_map[startGene].push_back(bank[i]);
      }
    }

    // Perform BFS by pushing a endGene to hash_map, and push neighbors to queue
    std::queue<std::pair<std::string, int>> queue;
    queue.push(std::make_pair(endGene,0));
    std::set<std::string> seen;
    
    seen.insert(endGene);
    while(!queue.empty()) {
      auto [node, steps] = queue.front();
      if(node == startGene) {
        return steps;
      }
      queue.pop();
      for(auto iter = hash_map[node].begin(); iter != hash_map[node].end(); iter++) {
        //int nextStep = steps + 1;
        if(seen.find(*iter) == seen.end()) {
          seen.insert(*iter);
          queue.push(std::make_pair(*iter, steps + 1));
        }
      }
    }
    return -1;
  }
};

int main() {
  //std::string startGene{"AACCGGTT"}, endGene{"AACCGGTA"};
  //std::vector<std::string> bank {"AACCGGTA"};

  //std::string startGene = "AACCGGTT", endGene = "AAACGGTA";
  //std::vector<std::string> bank{"AACCGGTA","AACCGCTA","AAACGGTA"};

  std::string startGene{"AACCGGTT"}, endGene{"AAACGGTA"};
  std::vector<std::string> bank{"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
  Solution s1;
  int ans = s1.minMutation(startGene, endGene, bank);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
