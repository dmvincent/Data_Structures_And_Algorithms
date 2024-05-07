#include <iostream>
#include <stack>
#include <limits.h>
#include <cmath>

class Solution {
public:
  int maximum69Number (int num) {
    int ans = 0;
    
    // Push each digit in nums onto a stack starting from the lowest place value.
    // Make sure to push the last digit onto the stack after the while loop
    int places = 0;
    std::stack<int> digits;
    while(num/10 != 0) {
      digits.push(num%10);
      num = num/10;
      places++;
    }
    digits.push(num);
    places++;

    // Append integers of stack and change first 6 to 9 if possible
    while(!digits.empty()) {
      if(digits.top() == 6) {
        ans = ans + 9*pow(10,--places);
        digits.pop();
        break;
      }
      ans = ans + digits.top()*pow(10,--places);
      digits.pop();
    }

    while(!digits.empty()) {
      ans = ans + digits.top()*pow(10,--places);
      digits.pop();
    }

    return ans;
  }
};

int main() {
  int num = 9669;

  Solution s1;
  int ans = s1.maximum69Number(num);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
