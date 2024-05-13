#include <iostream>
#include "include/Solution.hpp"

int main() {
    std::string input{"pwwkew"};
    Solution s1;
    int ans = s1.lengthOfLongestSubstring(input);
    std::cout << "Answer: " << ans << std::endl;
    return 0;
}
