#include <iostream>
#include "include/Solution.hpp"

int main() {
    std::string input{"leEeetcode"};
    Solution s1;
    std::string ans = s1.makeGood(input);
    std::cout << "Answer: " << ans << std::endl;
    return 0;
}
