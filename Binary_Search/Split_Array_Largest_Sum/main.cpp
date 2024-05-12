#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

class Solution {
public:
  int splitArray(std::vector<int>& nums, int k) {
    // Define Range of Possible Sums
    int left = 0;
    for(auto i: nums) {
      left = std::max(left, i);
    }
    int right = accumulate(nums.begin(), nums.end(), 0);


    // Start searching in between the bounds to compare the split sums with
    while(left <= right) {
      std::cout << "Checking in between " << left << " and " << right << std::endl;
      int mid = left + (right - left)/2;
      if(check(nums, k, mid)) {
        right = mid - 1; 
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  bool check(std::vector<int>& nums, int k, int mid) {
    int curr = 0;
    int chunks = 1;
    for(int i = 0; i < nums.size(); i++) {
      curr = curr + nums[i];
      if(curr > mid) {
        curr = 0;
        i--;
        chunks++;
      }
    }
    std::cout << "For mid = " << mid << ", there are " << chunks << " valid chunks" << std::endl;
    if(chunks <= k) {
      return true;
    }
    return false;
  }

};

int main() {
  std::vector<int> nums{7,2,5,10,8};
  int k = 2;

  //std::vector<int> nums{1,4,4};
  //int k = 3;

  Solution s1;
  int ans = s1.splitArray(nums, k);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
