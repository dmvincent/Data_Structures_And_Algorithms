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
        std::cout << "Set:    ";
        print(registry);
        std::unordered_map<int,int> hash_map(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            if(hash_map.find(arr[i]) != hash_map.end()) {
                hash_map[arr[i]] = hash_map[arr[i]] + 1;
            } else {
                hash_map[arr[i]] = 1;
            }
        }
        std::cout << "Hash_Map: ";
        print(hash_map);
        int ans = 0;
        int i = 0;
        for(auto s: registry) {
            if(hash_map.find(key) != hash_map.end()) {
                ans = ans + hash_map[key];
                std::cout << key << ": " << hash_map[key] << ": " << ans << std::endl;
            }
        }
        return ans;     
    }
};

int main() {
    std::vector<int> arr{1,3,2,3,5,0};
    std::cout << "Vector: {";
    for(auto a: arr) {
        std::cout << a << ", ";
    }
    std::cout << "}" << std::endl;
    
    Solution s1;
    int ans = s1.countElements(arr);
    std::cout << ans << std::endl;
    return 0;
}
