#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
  KthLargest(int k, std::vector<int>& nums) {
    for(auto& i: nums) {
      heap.push(i);
    }
    this->k = k;
  }
  
  int add(int val) {
    heap.push(val);
    while(heap.size() > k)
      heap.pop();
    return heap.top(); 
  }
private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
  int k;
};

int main() {
  //int k = 3;
  //std::vector<int> nums{4,5,8,2};
  //KthLargest* obj = new KthLargest(k, nums);
  //std::vector<int> stream{{3}, {5}, {10}, {9}, {4}};

  int k = 1;
  std::vector<int> nums{};
  KthLargest* obj = new KthLargest(k, nums);
  std::vector<int> stream{{-3},{-2},{-4},{0},{4}};


  for(auto& i: stream) {
    std::cout << obj->add(i) << std::endl;
  }
  return 0;
}
