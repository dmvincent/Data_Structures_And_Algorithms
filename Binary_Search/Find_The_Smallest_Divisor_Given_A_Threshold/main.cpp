#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

class Solution {
public:
  int smallestDivisor(std::vector<int>& nums, int threshold) {
    int left = 1;
    int right = INT_MAX;

    while (left <= right) {
      int mid = left + (right-left)/2;
      if(check(nums, threshold, mid)) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return left;
  }

  bool check(std::vector<int>& nums, int threshold, int mid) {
    int sum = 0;
    for(auto& i: nums) {
      sum += ceil((double)i/mid); 
    }
    if(sum <= threshold)
      return true;

    return false;
  }
};

int main() {
  //std::vector<int> nums{1,2,5,9};
  //int threshold = 6;

  Solution s1;
  int ans = s1.smallestDivisor(nums, threshold);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
