#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> ans(nums.size());
        int right = nums.size()-1;
        int left {0};
        int higher;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(abs(nums[left]) > nums[right]) {
                ans[i] = pow(nums[left],2);
                left++;
            } else {
                ans[i] = pow(nums[right],2);
                right--;
            }
        }
        return ans; 
    }
};

int main() {
    std::vector<int> nums {-7,-3,2,3,11};
    Solution s1;
    std::vector<int> ans = s1.sortedSquares(nums);
    for(auto i: ans)
        std::cout << i << std::endl;
    return 0;
}
