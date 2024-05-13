#include <iostream>
#include <vector>

class Solution {
public:
    int minStartValue(std::vector<int>& nums) {
        // Create prefix array
        std::vector<int> prefix(nums.size());

        // Initiate the start-value
        int ans;

        // Cycle through the rest of 'nums' and populate prefix array
        for(int i = 0; i < nums.size(); i++) {
            // Special case where i = 0
            if(i == 0) {
                prefix[i] = nums[i];
                ans = prefix[i];
            }          
            else {
                // Add prefix at i-1 to current prefix
                prefix[i] = nums[i] + prefix[i-1];

                if(prefix[i] < ans) ans = prefix[i];
            }
        }
        
        if(ans < 1) {
            return 1 - ans;
        } else {
            return 1;
        }
    }
};

int main() {

    std::vector<int> nums{1,-2,-3};
    Solution s1;
    int ans = s1.minStartValue(nums);
    std::cout << "Anser is: " << ans << std::endl;
    return 0;
}
