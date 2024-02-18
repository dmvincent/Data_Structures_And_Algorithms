#include <iostream>
#include <vector>

class Solution {
public:
    int largestUniqueNumber(std::vector<int>& nums) {
        int ans = -1;
        std::vector<int> presentNumberCount(1001, 0);
        for(auto n: nums) {
            presentNumberCount[n]++;
        }
        int i = presentNumberCount.size()-1;
        for(auto it = presentNumberCount.end()-1; it >= presentNumberCount.begin(); it--) {
            if(*it == 1) {
                ans = i;
                break;
            }
            i--;
        }
        return ans;
    }
};

int main(){
    int largestNumber;
    Solution s1;
    std::vector<int> nums {5,7,3,9,4,9,8,3,1};
    largestNumber = s1.largestUniqueNumber(nums);
    std::cout << "LargestNumber: " << largestNumber << std::endl;
    return 0;
}
