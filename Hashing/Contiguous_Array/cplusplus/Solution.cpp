#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
       int ans{0}, left{0}, right{0}; 
       // Special case where length of nums is less than 2
       if(nums.size() < 2)
           return ans;
       std::vector<int> prefix(nums.size());
       std::unordered_map<int,int> counts;
       prefix[0] = 0;
       int i = 1;
       //for(auto it = nums.begin(); it != nums.end();) {
       while(right < nums.size()) {
           counts[nums[right]]++;
           while((right - left) % 2) {
              // Expand the window right 
              right++;
              counts[nums[right]]++;
           }
       } 
       return ans;
    }

};

int main() {
    std::vector<int> nums{0,1};
    Solution s1;
    int ans = s1.findMaxLength(nums);
    std::cout << "Answer: " << ans << std::endl;
    return 0;
}
