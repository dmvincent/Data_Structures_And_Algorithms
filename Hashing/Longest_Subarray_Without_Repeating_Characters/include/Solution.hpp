#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int right{0}, left{0}, curr{0}, ans{0};
        std::unordered_map<char, int> char_count(s.size());
        for(;right < s.size();right++) {
            char_count[s[right]]++;
            while(char_count[s[right]] > 1)
                char_count[s[left++]]--;
            curr = right - left + 1;
            ans = (curr > ans) ? curr : ans;
        }        
        return ans;  
    }
};
