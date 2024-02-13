#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        std::vector<int> ans(nums.size());
        std::vector<int> prefix(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                prefix[i] = nums[i];
            } 
            else {
                prefix[i] = prefix[i-1] + nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i < k || i >= (nums.size() - k)) {
                ans[i] = -1;
            } else {
                ans[i] = (prefix[i+k] - prefix[i-k] + nums[i-k])/((2*k) + 1);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums{7,4,3,9,1,8,5,2,6};
    int k = 3;
    Solution s1;
    std::vector<int> ans = s1.getAverages(nums,k);
    for(auto x: ans) std::cout << x << std::endl;
    return 0;
}
