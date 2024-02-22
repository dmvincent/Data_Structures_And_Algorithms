#include <iostream>
#include <set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        int ans{0};
        std::set<char> jSet(jewels.begin(), jewels.end());
        for(auto& s: stones)
            if(jSet.find(s) != jSet.end())
                ans++;
        return ans;        
    }
};
