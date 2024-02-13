#include <vector>
#include <iostream>
#include <math.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int>::iterator leftIt = nums.begin();
        std::vector<int>::iterator rightIt = --nums.end();
        std::vector<int> ans;
        ans.push_back(pow(*rightIt,2));
        rightIt--;
        //while(leftIt != rightIt) {
        while(leftIt != rightIt) {
            *leftIt = pow(*leftIt,2);
            if(*leftIt == 9)
                std::cout << "I found it" << std::endl;
            if(*leftIt > *(--ans.end())) {
                *ans.end() = *leftIt;
            } else {
                ans.push_back(*leftIt);
            }
            leftIt++;
	    
        }
        return ans; 
    }
};

int main() {
    std::vector<int> nums{-4,-1,0,3,10};
    std::vector<int> ans;
    Solution s1;
    ans = s1.sortedSquares(nums);
    for(std::vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        std::cout << *it << std::endl;
    } 
    return 0;
}
