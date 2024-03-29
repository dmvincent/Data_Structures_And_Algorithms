#include <iostream>
#include <vector>
#include <deque>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if(root == NULL)
          return ans;
        bool flag = false;
        std::deque<TreeNode*> deque;
        TreeNode* node = new TreeNode;
        deque.push_back(root);
        bool conventional = true;
        while(!deque.empty()) {
          std::vector<int> inner;
          int size = deque.size();
          for(int i = 0; i < size; i++) {
            // Deque pops from the from and pushes child nodes to back from left to right
            if(conventional == true) {
              node = deque.front();
              deque.pop_front();
              if(node->left != NULL)
                deque.push_back(node->left);
              if(node->right != NULL)
                deque.push_back(node->right);
            }
            // Deque pops from the back and pushes child nodes to front from right to left
            else {
              node = deque.back();
              deque.pop_back();
              if(node->right != NULL)
                deque.push_front(node->right);
              if(node->left != NULL)
                deque.push_front(node->left);
            }
            inner.push_back(node->val);
          }
          ans.push_back(inner);
          conventional = !conventional;
        }
        return ans;
    }
};

int main() {

  TreeNode aRbL(15);
  TreeNode aRbR(7);
  TreeNode aL(9);
  TreeNode aR(20);
  TreeNode root(3);

  root.left = &aL;
  root.right = &aR;

  aR.left = &aRbL;
  aR.right = &aRbR;

  Solution s1;
  std::vector<std::vector<int>> ans = s1.zigzagLevelOrder(&root);
  for(auto m: ans) {
    for(auto n: m) {
      std::cout << n << ", ";
    }
    std::cout << std::endl;
  }

  return 0;
}
