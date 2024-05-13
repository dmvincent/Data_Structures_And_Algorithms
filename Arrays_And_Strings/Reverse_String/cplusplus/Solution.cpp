#include <iostream>
#include <vector>

class Solution {
public:
    Solution() = default;
    void reverseString(std::vector<char>& s) {
        std::vector<char>::iterator leftIt = s.begin();
        std::vector<char>::iterator rightIt = --s.end();
	while (leftIt < rightIt) {
            char temp = *leftIt;
            *leftIt = *rightIt;
            *rightIt = temp;
            leftIt++;
            rightIt--;
        }

        for(std::vector<char>::iterator it = s.begin(); it != s.end(); it++) {
            std::cout << *it << std::endl;
        }
    }   
};

int main() {
    std::vector<char> s;
    s.push_back('w');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');

    Solution sol1;
    sol1.reverseString(s);
  
    return 0;
}

