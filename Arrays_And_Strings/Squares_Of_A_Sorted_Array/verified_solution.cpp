#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int i=0,j=nums.size()-1, k=nums.size()-1;
        std::vector<int>v(nums.size(),0);
        while(i<=j)
        {
            if(abs(nums[i])>=abs(nums[j]))
             v[k--]=(pow(nums[i++],2));
            
            else v[k--]=(pow(nums[j--],2));
        }
        return v;
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
