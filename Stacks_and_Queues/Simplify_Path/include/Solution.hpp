#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string ans = "/";
        std::stack<std::string> dir;
        std::stack<std::string> swap;

        int i = 0;
        while(i < path.size()) {
            std::string val = "";
            while(path[i] != '/' && i < path.size()) {
                val.push_back(path[i]);
                i++;
            }

            if(val == ".." && dir.size() == 0) {
            }
            else if(val == "..") {
                dir.pop();
            }
            else if(val != "." && val != ""){
                dir.push(val);
            }

            i++;
        }
        while(!dir.empty()) {
            swap.push(dir.top());
            dir.pop();
        }
        while(!swap.empty()) {
            if(swap.size() == 1)
                ans = ans+swap.top();
            else
                ans = ans+swap.top()+"/";
            swap.pop();
        }
        return ans;
    }
};
