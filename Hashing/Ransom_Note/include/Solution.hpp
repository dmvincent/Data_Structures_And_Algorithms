#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        bool ans;
        // Put all characters from ransomNote into hash map mapping the
        // character-key to the number-value of times it appears in ransomNote
        std::unordered_map<char, int> char_map;
        for(auto c: ransomNote) {
            char_map[c]++;
        }
        for(auto c: magazine) {
            if(char_map.find(c) != char_map.end()) {
                char_map[c]--;
                if(char_map[c] == 0)
                    char_map.erase(c);
            }
        }
        ans = char_map.size() ? false : true; 
        return ans;   
    }
};
