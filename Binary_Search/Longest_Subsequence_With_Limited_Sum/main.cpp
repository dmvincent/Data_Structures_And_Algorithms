#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
  void printVector(std::vector<int>& vec) {
    std::cout << "[";
    for(int i = 0; i < vec.size(); i++) {
      if(i != vec.size() - 1)
        std::cout << vec[i] << ", ";
      else
        std::cout << vec[i] << "]" << std::endl << std::endl;
    }
  }
  std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
    std::vector<int> ans(queries.size(), 0);
    
    // Troubleshooting: Print OG nums
    std::cout << "Original Nums" << std::endl << "=======================" << std::endl;
    printVector(nums);

    // Create hash_map of nums values and their location
    // for verifying subsequence constraint later on
    std::unordered_map<int, int> hash_map;
    for(int i = 0; i < nums.size(); i++)
      hash_map[i] = i;
    
    // Sort nums array
    sort(nums.begin(), nums.end());

    // Troubleshooting: Print sorted nums
    std::cout << "Sorted Nums" << std::endl << "=======================" << std::endl;
    printVector(nums);

    // Troubleshooting: Print the query
    std::cout << "Query" << std::endl << "=======================" << std::endl;
    printVector(queries);

    // Find the first element in sorted nums array
    int max, left, right, mid;
    std::vector<int> max_loc(queries.size(), 0);
    for(auto i = 0; i < queries.size(); i++) {
      max = queries[i];
      left = 0;
      right = nums.size() - 1;
      while(left <= right) {
        mid = left + (right - left)/2;

        if(nums[mid] == max) {
          left = mid;
          break;
        }

        if(nums[mid] >= max)
          right = mid - 1;
        else
          left = mid + 1;
      }
      max_loc[i] = left;
    }
    
    // Troubleshooting: Print location where query cieling is in sorted nums array
    std::cout << "Query Cieling Location in sorted nums" << std::endl << "=======================" << std::endl;
    printVector(max_loc);

    

    return ans;
  }
};

int main() {
  std::vector<int> nums{4,5,2,1};
  std::vector<int> queries{3,10,21};

  Solution s1;
  std::vector<int> ans = s1.answerQueries(nums, queries);
  std::cout << "Answer" << std::endl << "==================" << std::endl;
  for(auto iter = 0; iter < ans.size(); iter++) {
    std::cout << queries[iter] << ": " << ans[iter] << std::endl;
  }

  return 0;
}
