#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
  bool dfs(std::vector<int>& arr, int start, std::unordered_map<int, std::pair<int,int>>& hash_map, std::vector<int>& seen) {
    if(seen[start])
      return false;
    seen[start] = 1;
    if(arr[start] == 0)
      return true;
    if(start == -1)
      return false;
    if(hash_map[start].first != -1)
      if(dfs(arr, hash_map[start].first, hash_map, seen))
        return true;
    if(hash_map[start].second != -1)
      if(dfs(arr, hash_map[start].second, hash_map, seen))
        return true;

    return false;
  }
  bool canReach(std::vector<int>& arr, int start) {
    if((start + arr[start]) > arr.size() && (start - arr[start]) < 0)
      return false;

    // Create Hash Map
    std::unordered_map<int, std::pair<int,int>> hash_map;
    for(int i = 0; i < arr.size(); i++) {
      if(i+arr[i] < arr.size() || i-arr[i] >= 0) {
        hash_map[i] = std::make_pair(-1, -1);
        if(i+arr[i] < arr.size())
          hash_map[i].first = i + arr[i];
        if((i-arr[i]) >= 0)
          hash_map[i].second = i - arr[i];
      }
    }

    // Run DFS
    std::vector<int> seen(arr.size(), 0);
    bool ans = dfs(arr, start, hash_map, seen);

    return ans;
  }
};

int main() {
  std::vector<int> arr{4,2,3,0,3,1,2};
  int start{5};
  //std::vector<int> arr{4,2,3,0,3,1,2};
  //int start = 0;
  //std::vector<int> arr{3,0,2,1,2};
  //int start = 2;
  //std::vector<int> arr{5,11,18,16,21,3,19,0,16,4,9,20,2,13,0,2,23,8,19,22,16,19,19,25,25,15,7};
  //int start = 18;
  Solution s1;
  bool ans = s1.canReach(arr, start);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
