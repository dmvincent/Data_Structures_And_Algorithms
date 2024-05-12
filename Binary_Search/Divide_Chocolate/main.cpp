#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
  int max = 0;
  void printVector(std::vector<int>& vec, std::string msg) {
    std::cout << msg << std::endl << "==================" << std::endl;
    std::cout << "[";
    for(int i = 0; i < vec.size(); i++) {
      if(i != vec.size() - 1)
        std::cout << vec[i] << ", ";
      else
        std::cout << vec[i];
    }
    std::cout << "]" << std::endl << std::endl;
  }

  int maximizeSweetness(std::vector<int>& sweetness, int k) {
    int ans;
    //// Task: Find maximum sweetness of the piece you can get such that everyone elses
    ///        piece has an accumulated total sweetness greater than yours
    ///  Approach: Search for a value between the possible minimum and maximum values
    ///            for sweetness that allows the remaining sweetness values to be grouped
    ///            into consecutive segments whose sums are greater than your piece
    //// Algorithm:
    //      1. Create prefix array tracking the running sum of sweetness elements
    //      2. Define the min(left) and max(right) for possible maximum_total_sweetness
    //      3. Search in between the left and right bounds checking each time 
    //         whether or not the middle element satisfies the condition

    // Troubleshooting: Pring prefix array
    printVector(sweetness, "Sweetness Array");

    // Create Prefix Array and retrieve the max element as well from sweetness while 
    // you're at it
    // Create Hash_Map to show where each element of sweetness is as well
    int maxElement = 0;
    std::vector<int> prefix(sweetness.size(), 0);
    //std::vector<int> loc(sweetness.size(),0);
    prefix[0] = sweetness[0];
    //maxElement = sweetness[0];
    //loc[sweetness[0]] = 0;

    for(int i = 1; i < prefix.size(); i++) {
      prefix[i] = sweetness[i] + prefix[i-1];
      //maxElement = std::max(maxElement, sweetness[i]);
      //loc[sweetness[i]] = i;
    }

    // Troubleshooting: Pring prefix array and max element and element locations
    //std::cout << "Max Element: " << maxElement << std::endl;
    printVector(prefix, "Prefix Array");
    //printVector(loc, "Element locations in Sweetness");

    // Define the min (left) and max(right) for possible maximum_total_sweetness
    int left = 1;
    int right = sweetness.size() - k;

    // Seach in between the min and max for the maximum_total_sweetness
    int mid = 0;
    while (left < right) {
      mid = left + (right - left) / 2 + 1;
      if(!check(sweetness, prefix, mid, k)) {
        left = mid;
      }
      else {
        right = mid - 1;
      }
    }
     
    return max;
  }

  int countElements(std::vector<int>& sweetness, int start, int end, int windowSum) {
    int count = 0;
    int curr = 0;
    for(int i = start; i < end; i++) {
      curr = curr + sweetness[i];
      if(curr > windowSum) {
        count++;
        curr = 0;
      }
    }
    return count;
  }

  bool check(std::vector<int>& sweetness, std::vector<int>& prefix, int mid, int k) {
    // Check Left Side
    bool flag = false;
    int left = 0;
    int right = mid - 1;
    int windowSum = prefix[mid - 1];
    int count = 0;
    while(right < sweetness.size()) {
      if(left == 0) {
        count += countElements(sweetness, right+1, sweetness.size(), windowSum);
      } else if(right == sweetness.size() - 1) {
        count += countElements(sweetness, 0, left, windowSum);
      } else {
        count += countElements(sweetness, 0, left, windowSum);
        count += countElements(sweetness, right+1, sweetness.size(), windowSum);
      }
      
      if(count >= k) {
        max = std::max(max, windowSum);
        flag = true;
      }

      right++;
      left++;
      windowSum = prefix[right] - prefix[left] + sweetness[left];
    }
    return flag;
  }

};

int main() {
  std::vector<int> sweetness{1,2,3,4,5,6,7,8,9};
  int k = 5;

  Solution s1;
  int ans = s1.maximizeSweetness(sweetness, k);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
