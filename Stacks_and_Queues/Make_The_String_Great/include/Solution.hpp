#include <iostream>
#include <stack>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::string ans;
        std::string singles;         
        std::stack<char> temp;         
        singles.push_back(s[0]);
        for(int i = 1; i < s.size(); i++) {
            while(singles.back() == s[i]) {
                singles.pop_back();
            }
            singles.push_back(s[i]);
        }
        return singles;
    }
};
