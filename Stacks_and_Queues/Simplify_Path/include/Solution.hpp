#include <iostream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string ans;
        
        for(int i = 0; i != path.size(); i++){
            if(path[i] == '.' || path[i] == '/') {
                if(path[i] == '.') {
                    if(ans.back() == '.')
                        ans.pop_back();
                }
                if(path[i] == '/') {

                }
            } else {
                ans.push_back(path[i]);
            }
        }

        return ans; 
    }
};
