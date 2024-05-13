#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
  int maxNumberOfApples(std::vector<int>& weight) {
    int ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(weight.begin(), weight.end());

    int curr = 0;
    while(!min_heap.empty() && curr < 5000) {
      curr += min_heap.top();
      ans++;
      min_heap.pop();
      if(curr > 5000) {
        ans--;
        break;
      }
    }
    return ans; 
  }
};

int main() {
  //std::vector<int> weight{100,200,150,1000};
  std::vector<int> weight{900,950,800,1000,700,800};

  Solution s1;
  int ans = s1.maxNumberOfApples(weight);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}


