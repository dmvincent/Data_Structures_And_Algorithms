#include <iostream>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;

    while(left <= right) {
      mid = left + (right - left)/2; 
      if(nums[mid] == target) {
        return mid;
      }

      if(nums[mid] >= target) {
        right = mid-1;
      }
      else {
        left = mid + 1;
      }
    }

    return left;    
  }
};

int main() {
  std::vector<int> nums {1,3,5,6};
  int target = 5;

  Solution s1;
  int ans = s1.searchInsert(nums, target);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
