#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::string curr;
    int open{0}, close{0}, count{0};
    backtrack(ans, curr, n, open, close, count);


    return ans;
  }

  void backtrack(std::vector<std::string>& ans, std::string& curr, int n, int& open, int& close, int& count) {
    if(curr.size() == 2*n) {
      ans.push_back(curr);
      return;
    }

    if(count < n/2)
      return;

    if(open < close) {
      curr.push_back('(');
      open++; count++;
      backtrack(ans, curr, n, open, close, count);
      open--; count--;
      curr.pop_back();
      return;
    }
    
    curr.push_back('(');
    open++; count++;
    backtrack(ans, curr, n, open, close, count);
    open--; count--;
    curr.pop_back();

    curr.push_back(')');
    close++; count++;
    backtrack(ans, curr, n, open, close, count);
    close--; count--;
    curr.pop_back();
    return;
  }

};

int main() {
  int n = 3;

  Solution s1;
  std::vector<std::string> ans = s1.generateParenthesis(n);

  std::cout << "Answer" << std::endl << "====================" << std::endl;
  for(auto& i: ans)
    std::cout << i << std::endl;

  return 0;
}
