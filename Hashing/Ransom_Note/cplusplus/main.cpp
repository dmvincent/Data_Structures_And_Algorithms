#include <iostream>
#include <vector>
#include <unordered_set>
#include "include/Solution.hpp"

int main() {

    Solution s1;

    std::string ransomNote{"aa"};
    std::string magazine{"aab"};
    bool ans = s1.canConstruct(ransomNote, magazine);
    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
