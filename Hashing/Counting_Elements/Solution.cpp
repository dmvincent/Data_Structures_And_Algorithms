#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

void print(auto const& map)
{
    std::cout << '{';
    for (const auto& pair : map)
        std::cout << '{' << pair.first << ": " << pair.second << '}';
    std::cout << "}\n";
}

void print(std::set<int>& input)
{
    std::cout << '{';
    for (const auto& value : input)
        std::cout << value << ", ";
    std::cout << "}\n";
}



class Solution {
public:
    int countElements(std::vector<int>& arr) {
        std::set<int> registry(arr.begin(), arr.end());
        int ans = 0;
        for(auto a: arr) {
            if(registry.find(a+1) != registry.end())
                ans++;
        }
        return ans;     
    }
};

int main() {
    std::vector<int> arr{1,3,2};
    Solution s1;
    int ans = s1.countElements(arr);
    std::cout << ans << std::endl;
    return 0;
}
