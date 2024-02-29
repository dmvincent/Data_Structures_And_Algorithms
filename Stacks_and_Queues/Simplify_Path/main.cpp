#include <iostream>
#include "include/Solution.hpp"

int main() {

    //std::string path = "/home/";
    std::string path = "/a/./b/../../c/";
    Solution s1;
    std::string ans = s1.simplifyPath(path);
    std::cout << ans << std::endl;

    return 0;
}
