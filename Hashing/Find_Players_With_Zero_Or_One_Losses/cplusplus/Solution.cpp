#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

void print(std::unordered_map<int,int> hash_map, std::string comment) {

    std::cout << comment << std::endl;
    std::cout << "---------------------" << std::endl;
    
     
    for(auto& hmr: hash_map) {
        std::cout << hmr.first << " : " << hmr.second << std::endl;
    }
    std::cout << std::endl;

}

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        // Prepare return value
        // Prepare unordered map to map wins/losses to players
        std::unordered_map<int,int> wins;
        std::unordered_map<int,int> losses;
        // Go through entire array    
        for(auto& m: matches) {
            wins[m[0]]++;
            losses[m[1]]++;
        }
        // Convert Wins to set to get list of whoever won at least one game
        std::set<int> winners; 
        for(auto& w: wins)
            winners.insert(w.first);
         
        // Convert losses to set to get list of whoever lost at least one game
        std::set<int> losers; 
        for(auto& l: losses)
            losers.insert(l.first);
        
        // Remove any names that are in the losers set from the winners, and any player with one loss to a one_loss set
        std::set<int> one_loss;
        for(auto it = losses.begin(); it != losses.end(); it++) {
            if(it->second == 1)
                one_loss.insert(it->first);
            if(winners.find(it->first) != winners.end())
                winners.erase(it->first);
        }
      
        std::vector<int> ansWinners(winners.begin(), winners.end());
        std::vector<int> ansOneLoss(one_loss.begin(), one_loss.end());
        std::vector<std::vector<int>> ans(2, std::vector<int> (std::max(winners.size(), one_loss.size())));
        ans[0] = ansWinners;
        ans[1] = ansOneLoss;
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> matches{{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    Solution s1;
    std::vector<std::vector<int>> ans = s1.findWinners(matches);

    return 0;
}
