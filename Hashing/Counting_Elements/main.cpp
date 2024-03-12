#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int countElements(std::vector<int>& arr) {
        std::set<int> seen(arr.begin(), arr.end());
        int count{0};
        for(auto i: arr) {
            if(seen.find(i+1) != seen.end())
                count++;
        }
        return count;
    }
};

int main() {
    std::vector<int> arr {1,3,2,3,5,0};
    Solution s1;
    int ans = s1.countElements(arr);
    std::cout << "Answer is: " << ans << std::endl;

    return 0;
}
