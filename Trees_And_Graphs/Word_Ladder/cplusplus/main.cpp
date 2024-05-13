#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>

using namespace std;
class Solution {
public:
    void createHashMap(unordered_map<string, vector<string>>& hash_map, string& beginWord, vector<string>& wordList) {
      for(int i = 0; i < wordList.size(); i++) {
        for(int j = i+1; j < wordList.size(); j++) {
          int count = 0;
          for(int e = 0; e < wordList[i].size(); e++) {
            if(wordList[i][e] != wordList[j][e])
              count++;
          }
          if(count == 1) {
            hash_map[wordList[i]].push_back(wordList[j]);
            hash_map[wordList[j]].push_back(wordList[i]);
          }
        }

        // Check for the beginWord to include in hash_map
        int count = 0;
        for(int e = 0; e < beginWord.size(); e++) {
          if(beginWord[e] != wordList[i][e]) {
            count++;
          }
        }

        if(count == 1) {
          hash_map[beginWord].push_back(wordList[i]);
          hash_map[wordList[i]].push_back(beginWord);
        }
      }  
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      // Make Hash Map
      unordered_map<string, vector<string>> hash_map;
      int firstNode;
      createHashMap(hash_map, beginWord, wordList);
      // Handle corner case where endWord has no neighbors
      if(hash_map.find(endWord) == hash_map.end())
        return 0;

      // Start BFS from beginWord in hashMap
      set<string> seen;
      queue<pair<string, int>> queue; // node, steps

      seen.insert(beginWord);
      queue.push(make_pair(beginWord, 1));
      int min = INT_MAX;
      while(!queue.empty()) {
        auto [node, curr] = queue.front();
        queue.pop();
        if(node == endWord)
          min = std::min(min, curr);
        for(auto iter = hash_map[node].begin(); iter != hash_map[node].end(); iter++) {
          if(seen.find(*iter) == seen.end()) {
            seen.insert(*iter);
            queue.push(make_pair(*iter, curr+1));
          }
        }
      }

      min = (min==INT_MAX)?0:min;


      return min;        
    }
};


int main() {
  // Input
  string beginWord{"hit"}, endWord{"cog"};
  vector<string> wordList{"hot","dot","dog","lot","log","cog"};
  
  //string beginWord{"hit"}, endWord{"cog"};
  //vector<string> wordList{"hot","dot","dog","lot","log"};

  // Implement Method
  Solution s1;
  int ans = s1.ladderLength(beginWord, endWord, wordList);
  cout << "Answer: " << ans << endl;
  return 0;
}
