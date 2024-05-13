#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

class StockSpanner {
public:
    std::stack<int> stackEm;
    std::unordered_map<int,int> map;
    int day{1};
    
    StockSpanner() {

    }   
    
    int next(int price) {
        int val{0};
        int diff;
    
        map[price] = day;


        while(!stackEm.empty() && stackEm.top() <= price) {
            stackEm.pop();
        }

        if(stackEm.empty()) {
            val = day++;
        } else {
            val = day++ - map[stackEm.top()];    
        }

        stackEm.push(price);

        return val;
    }
};

int main() {
    std::vector<std::vector<int>> price{{1},{79},{34},{21},{34},{16},{59},{63},{72},{5}};
    StockSpanner s1;
    for (auto n: price) {
        for(auto m: n) {
            int ans = s1.next(m);
            std::cout << "Answer: " << ans << std::endl;
        }
    }
    return 0;
}
