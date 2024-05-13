#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::vector<std::vector<int>> ans;

    // Push elements of points into max heap, and pop whenever elements in heap exceed k
    std::priority_queue<std::pair<double,int>> heap;
    int i = 0;
    for(auto& e: points) {
      heap.push(std::make_pair(sqrt(pow(e[0], 2) + pow(e[1], 2)), i));
      if(heap.size() > k)
        heap.pop();
      i++;
    }

    // Transfer all elements from heap into answer vector
    while(!heap.empty()) {
      ans.push_back(points[heap.top().second]);
      heap.pop();
    }
    return ans;
  }
};

int main() {
  //std::vector<std::vector<int>> points{{1,3},{-2,2}};
  //int k = 1;

  //std::vector<std::vector<int>> points{{3,3},{5,-1},{-2,4}};
  //int k = 2;

  //std::vector<std::vector<int>> points{{0,1}, {1,0}};
  //int k = 2;

  std::vector<std::vector<int>> points{{1,3},{-2,2},{2,-2}};
  int k = 2;


  Solution s1;
  std::vector<std::vector<int>> ans = s1.kClosest(points, k);

  std::cout << "Answer" << std::endl << "==================" << std::endl;
  for(auto i: ans) {
    std::cout << i[0] << ", " << i[1] << std::endl;
  }

  return 0;
}
