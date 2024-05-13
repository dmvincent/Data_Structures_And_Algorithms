#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
  int connectSticks(std::vector<int>& sticks) {
    // Declare return variable
    int ans{0};

    // Define the priority_queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap(sticks.begin(), sticks.end());

    //while(!heap.empty()) {
    //  std::cout << heap.top() << std::endl;
    //  heap.pop();
    //}

    //Combine the sticks until only one stick left
    int iter = 1;
    int curr = 0;
    while(iter < sticks.size()) {
      // Combine first two elements in queue and pop them off
      curr = heap.top();
      heap.pop();
      curr += heap.top();
      heap.pop();

      // Push the freshly combined stick back into the queue
      heap.push(curr);

      // Increment the ans and iter variables
      ans += curr;
      iter++;

      // Reset the curr variable
      curr = 0;
    }
    
    return ans;
  }
};

int main() {
  std::vector<int> sticks{2,4,3};

  Solution s1;
  int ans = s1.connectSticks(sticks);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
