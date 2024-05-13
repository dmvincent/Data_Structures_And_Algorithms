#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
  int minStoneSum(std::vector<int>& piles, int k) {
    int min = 0;
    std::priority_queue<int> heap(piles.begin(), piles.end());
    int half;
    int push;
    //std::cout << "Removing" << std::endl << "==========" << std::endl;
    while(!heap.empty() && k > 0) {
      half = heap.top()/2;
      //std::cout << half << std::endl;
      push = heap.top() - half;
      heap.pop();
      heap.push(push);
      k--;
    }
    //std::cout << "Summing Up" << std::endl << "==========" << std::endl;
    while(!heap.empty()) {
     // std::cout << heap.top() << std::endl;
      min = min + heap.top();
      heap.pop();
    }
    return min;
  }
};

int main() {
  std::vector<int> piles{5,4,9};
  int k = 2;

  Solution s1;
  int ans = s1.minStoneSum(piles, k);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
