#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> ans;
    std::string curr = {};
    if(digits == "")
      return {};
    
    // Start the backtrackint Function
    backtrack(digits, curr, ans, 0);
    

    //// Troublshoot: Print Hash Map
    //std::cout << "HashMap" << std::endl << "===================" << std::endl;
    //for(int i = 0; i < hash_map.size(); i++) {
    //  std::cout << digits[i] << ": ";
    //  for(int j = 0; j < hash_map[i].size(); j++) {
    //    if(j < hash_map[i].size() - 1) 
    //      std::cout << hash_map[i][j] << ", ";
    //    else
    //      std::cout << hash_map[i][j] << std::endl;
    //  }
    //}

    return ans;
  }

  void backtrack(std::string& digits, std::string& curr, std::vector<std::string>& ans, int i) {
    // Base case should return when the size of the string to be added to 2d answer vector reachs
    // the correct size
    if(curr.size() == digits.size()) {
      ans.push_back(curr);
      return;
    }

    // Add the letters assocatiated with the i'th button to the current string
    int limit, j;
    char currChar;
    for(;i < digits.size(); i++) {
      int num = (int)(digits[i] - 48);
      //std::cout << num << ": ";
      if(num == 7 || num == 9)
        limit = 4;
      else
        limit = 3;
      j = 0;
      while(j < limit) {
        if(num <= 7) 
          currChar = (char)((num - 2)*3 + j + 97);
        else
          currChar = (char)((num - 2)*3 + j + 1 + 97);
        
        curr.push_back(currChar);
        backtrack(digits, curr, ans, i+1);
        curr.pop_back();
        j++;
      }
    }
  }
};

int main() {
  std::string digits = "23";

  Solution s1;
  std::vector<std::string> ans = s1.letterCombinations(digits);
  for(auto& s: ans)
    std::cout << s << std::endl;

  return 0;
}
