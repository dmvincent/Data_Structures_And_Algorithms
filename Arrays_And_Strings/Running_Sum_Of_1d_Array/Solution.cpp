#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> sum{nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            //sum[i] = sum[i-1] + nums[i];
            sum.push_back(sum[i-1] + nums[i]);
        }            
        return sum;
    }
};

int main() {
    std::vector<int> nums {3,1,2,10,1};
    Solution s1;
    std::vector<int> result;
    result = s1.runningSum(nums);
    for(auto x: result) {
        std::cout << x << std::endl;
    }
    return 0;
}
