#include <iostream>
#include <vector>
#include <set>
#include <queue>
//#include <pair>

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
    std::set<std::string> allowed(bank.begin(), bank.end());
    int count{0};
    
    // Make sure that the endGene is a valud gene
    if(allowed.find(endGene) == allowed.end()) {
      return -1;
    }

    // Create of set containing the indices of startGene that differ fron endGene
    std::set<int> mutate;
    for(int i = 0; i != startGene.size(); i++) {
      if(startGene[i] != endGene[i])
        mutate.insert(i);
    }

    std::queue<std::pair<std::string, int>> queue;
    queue.push(std::make_pair(startGene, 0));
    std::queue<int> removeQueue;

    int tempSteps{0};
    while(!queue.empty()) {
      auto [temp, steps] = queue.front();
      if(temp == endGene)
        return steps;
      queue.pop();
      std::string newTemp;
      for(auto iter = mutate.begin(); iter != mutate.end(); iter++) {
        newTemp = temp;
        newTemp[*iter] = endGene[*iter];
        std::cout << newTemp << std::endl;
        if(allowed.find(newTemp) != allowed.end()) {
          std::cout << "Hello" << std::endl;
          queue.push(std::make_pair(newTemp, steps + 1));
          removeQueue.push(*iter);
          //mutate.erase(*iter);
        }
      }
      while(!removeQueue.empty()) {
        mutate.erase(removeQueue.front());
        removeQueue.pop();
      }
    }

    std::cout << tempSteps << std::endl;
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
