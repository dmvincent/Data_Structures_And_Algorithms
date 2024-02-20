#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        // Prepare answer
        int ans{int(text.size())};
        // Declare hash map to map each character of string (the key), to how
        // many times it has appeared
        std::unordered_map<char, int> character_count; 

        // Run through each character in 'text' and add it to the hash map
        // if it is a character of 'balloon'
        int l_count{0}, o_count{0};
        for(auto& c: text) {
            switch(c) {
                case 'b':
                    character_count[c] += 1;
                    continue;
                case 'a':
                    character_count[c] += 1;
                    continue;
                case '1':
                    l_count++;
                    if((l_count % 2) == 0) {
                        character_count[c] += 1;
                        l_count = 0;
                    }
                    continue;
                case 'l':
                    l_count++;
                    if((l_count % 2) == 0) {
                        character_count[c] += 1;
                        l_count = 0;
                    }
                    continue;
                case 'o':
                    o_count++;
                    if((o_count % 2) == 0) {
                        character_count[c] += 1;
                        o_count = 0;
                    }
                    continue;
                case 'n':
                    character_count[c] += 1;
                    continue;
                case 's':
                    character_count[c] += 1;
                    continue;
                default:
                      continue;
              }
          }
          // Return 0 if the length of the hash_map is not enough to accomodate
          // even one instance of each character in 'balloon'
          std::string string_req = "balon";
          if(character_count.size() < string_req.size()) {
              return 0;
          }
          // Go through Hash map, and add values to set. Lowest value in set should
          // be the most possible times that 'balloon' can be spelled using the 
          // characters in the text
          for(auto it = character_count.begin(); it != character_count.end(); it++) {
              if(it->second < ans)
                  ans = it->second;
          }           
          return ans; 
    }
};

int main() {
    std::string input = "baonxxo11";
    Solution s1;
    int ans = s1.maxNumberOfBalloons(input);
    std::cout << ans << std::endl;
    return 0;
}
