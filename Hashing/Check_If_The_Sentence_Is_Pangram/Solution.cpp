#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::unordered_set<char> c1;
        // First check if length of string is at least the length of the alphabet
        if(sentence.size() < 26) {
            std::cout << "Size is: " << sentence.size() << std::endl;
            return false;
        }

        // Now add each character value from string to hash map only if it not
        // already in the hash map
        for(int i = 0; i < sentence.size(); i++) {
            if(c1.find(sentence[i]) != c1.end()) {
                // Exit For-Loop for one round
                continue;
            }
            // add character at i in string to hash map
            c1.insert(sentence[i]);
            std::cout << sentence[i] << std::endl;
        } 
        if(c1.size() < 26) return false;
        return true;
    }
};

int main() {

    std::string sentence = "abcdefghijklmnopqrstuvxyz";
    Solution s1;
    bool res = s1.checkIfPangram(sentence);
    std::cout << "Result is: " << res << std::endl;
    return 0;
}
