#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    // Initialize the heap with elements in nums
    std::priority_queue<int> heap(nums.begin(), nums.end());

    // Cycle through just nums just enough times to stop at the kth largest element
    int iter = 1;
    while(iter++ < k)
      heap.pop();

    return heap.top();
  }
};

int main() {
  std::vector<int> nums{3,2,1,5,6,4};
  int k = 2;

  Solution s1;
  
  std::cout << "Answer: " << s1.findKthLargest(nums, k) << std::endl;
  return 0;
}
