#include <iostream>
#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left{0}, ans{0}, curr{0};
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0)
                curr++;
            while(curr > k) {
                if(nums[left] == 0) {
                    curr--;
                }
                left++;
            }
            if((right-left+1) > ans) ans = (right-left+1);
        }
        return ans; 
    }
};

int main() {
    std::vector<int> nums {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    Solution s1;
    std::cout << "Answer is: " << s1.longestOnes(nums, k) << std::endl;
    return 0;
}
