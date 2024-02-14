#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int ans{0};
        std::set<int> s1(nums.begin(), nums.end());        
        for(int i = 0; i <= nums.size(); i++) {
            if(s1.find(i) == s1.end()) {
                ans = i; 
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s1;
    std::vector<int> nums{3,0,1};
    int res = s1.missingNumber(nums);
    std::cout << res << std::endl;
    return 0;
}
