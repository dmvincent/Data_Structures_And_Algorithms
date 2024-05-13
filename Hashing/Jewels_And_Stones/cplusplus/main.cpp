#include <iostream>
#include <vector>
#include "include/Solution.hpp"

int main() {
    std::string jewels{"z"};
    std::string stones{"ZZ"};

    Solution s1;
    int ans = s1.numJewelsInStones(jewels, stones);
    std::cout << "Answer: " << ans << std::endl;
    return 0;
}
