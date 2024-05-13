#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
  int minSetSize(std::vector<int>& arr) {
    int ans = 0;

    // Create Hash_map where the number of occurences of each key (integer in arr) is the value
    std::unordered_map<int, int> hash_map;
    for(auto i: arr)
      hash_map[i]++;

    // Push values from hash_map to max_heap
    std::priority_queue<int> max_heap;
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) 
      max_heap.push(iter->second);

    // Pop from max heap until sum of popped values is at least half of the size of arr
    int curr = arr.size();
    while (!max_heap.empty() && curr > arr.size()/2) {
      curr -= max_heap.top();
      max_heap.pop();
      ans++;
    }
    return ans;
  }
};

int main() {
  std::vector<int> arr{3,3,3,3,5,5,5,2,2,7};

  Solution s1;
  int ans = s1.minSetSize(arr);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
