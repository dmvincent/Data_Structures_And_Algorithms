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

    // Sort nums array
    sort(nums.begin(), nums.end());

    // Troubleshooting: Print sorted nums
    std::cout << "Sorted Nums" << std::endl << "=======================" << std::endl;
    printVector(nums);

    // Create Vector tracking running sums in sorted_nums
    std::vector<int> runningSortedSums(nums.size(), 0);
    int sum = 0;
    runningSortedSums[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      runningSortedSums[i] = runningSortedSums[i-1] + nums[i];
    }

    // Troubleshooting: Print Running Sums
    std::cout << "Running Sorted Sums" << std::endl << "=======================" << std::endl;
    printVector(runningSortedSums);

    
    //// Troubleshooting: Print the query
    //std::cout << "Query" << std::endl << "=======================" << std::endl;
    //printVector(queries);

    // Find location for maintaining sort in runningSortedSums for each query
    int max, left, right, mid;
    std::vector<int> runningSortedSumsLocation(queries.size(), 0);
    for(auto i = 0; i < queries.size(); i++) {
      max = queries[i];
      left = 0;
      right = runningSortedSums.size() - 1;
      while(left <= right) {
        mid = left + (right - left)/2;

        if(runningSortedSums[mid] == max) {
          left = mid + 1;
          break;
        }

        if(runningSortedSums[mid] >= max)
          right = mid - 1;
        else
          left = mid + 1;
      }
      runningSortedSumsLocation[i] = left;
    }
    
    //// Troubleshooting: Print location where query cieling is in sorted nums array
    //std::cout << "Query Cieling Location in sorted nums" << std::endl << "=======================" << std::endl;
    //printVector(runningSortedSumsLocation);

    

    return runningSortedSumsLocation;
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
