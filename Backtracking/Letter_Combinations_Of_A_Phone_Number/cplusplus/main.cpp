#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> ans;
    std::string curr = {};
    std::vector<std::vector<char>> hash_map(digits.size()); 
    if(digits == "")
      return {};
    
    //// Create Hash Map
    int limit, j;
    char currChar;
    for(int i = 0; i < digits.size(); i++) {
      std::vector<char> temp = {};
      int num = (int)(digits[i] - 48);
      //std::cout << num << ": ";
      if(num == 7 || num == 9)
        limit = 4;
      else
        limit = 3;
      j = 0;
      while(j < limit) {
        if(num <= 7) {
          currChar = (char)((num - 2)*3 + j + 97);
        } else {
          currChar = (char)((num - 2)*3 + j + 1 + 97);
        }
        
        //// Troubleshoot: Print the characters pertaining to each each digit in digits[]
        //if(j == limit - 1)
        //  std::cout << currChar << std::endl;
        //else
        //  std::cout << currChar << ", ";
        
        // Add the currect character to the hash map
        temp.push_back(currChar);
        j++;
      }
      hash_map[i] = temp;
    }

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


    backtrack(digits, curr, ans, 0, hash_map);

    return ans;
  }

  void backtrack(std::string& digits, std::string& curr, std::vector<std::string>& ans, int i, std::vector<std::vector<char>>& hash_map) {
    //std::cout << "Backtracking" << std::endl;
    if(curr.size() == digits.size()) {
      //std::cout << "Pushing curr to ans" << std::endl;
      ans.push_back(curr);
      //std::cout << "Successfull push to ans" << std::endl;
      return;
    }

    for(int j = 0; j < hash_map[i].size(); j++) {
      //std::cout << "Pushing '" << hash_map[i][j] << "'" << std::endl;
      curr.push_back(hash_map[i][j]);
      backtrack(digits, curr, ans, i+1, hash_map);
      curr.pop_back();
    }
  }
};

int main() {
  std::string digits = "";

  Solution s1;
  std::vector<std::string> ans = s1.letterCombinations(digits);
  for(auto& s: ans)
    std::cout << s << std::endl;

  return 0;
}
