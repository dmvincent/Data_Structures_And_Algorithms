#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


class Solution {
public:
  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    int ans = 0;

    // Create the hash_map where number of units per
    std::unordered_map<int, int> hash_map;
    for(auto& box: boxTypes) {
      hash_map[box[1]] += box[0]; 
    }

    // Create priority queue from hash_map
    std::priority_queue<std::pair<int,int>> heap;
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
      heap.push(std::make_pair(iter->first, iter->second));


    // Find max number of units
    int numBoxes = 0;
    while(numBoxes < truckSize && !heap.empty()) {
      ans += heap.top().first * heap.top().second;
      numBoxes += heap.top().second;
      while(numBoxes > truckSize) {
        ans -= heap.top().first;
        numBoxes -= 1;
      }
      heap.pop();
    }

    return ans;
  }
};

int main() {
  //std::vector<std::vector<int>> boxTypes{{1,3},{2,2},{3,1}};
  //int truckSize = 4; 

  std::vector<std::vector<int>> boxTypes{{5,10},{2,5},{4,7},{3,9}};
  int truckSize = 10;

  Solution s1;
  int ans = s1.maximumUnits(boxTypes, truckSize);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
