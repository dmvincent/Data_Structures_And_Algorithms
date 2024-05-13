#include <iostream>

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
    bool flag = false;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root == NULL) {
        flag = true; 
        return root;
      }
      if(root->val > val) {
        insertIntoBST(root->left, val);
        if(flag == true) {
          flag = false;
          TreeNode* node = new TreeNode(val);
          root->left = node;
        }
      }
      if(root->val < val) {
        insertIntoBST(root->right, val);
        if(flag == true) {
          flag = false;
          TreeNode* node = new TreeNode(val);
          root->right = node;
        }
      }

      return root;
    }
};

int main() {

  TreeNode* aLbL = new TreeNode; 
  TreeNode* aLbR = new TreeNode; 
  TreeNode* aL = new TreeNode; 
  TreeNode* aR = new TreeNode; 
  TreeNode* root = new TreeNode; 

  aL->left = aLbL;
  aL->right = aLbR;
  root->left = aL;
  root->right = aR;

  root->val = 4;
  aL->val = 2;
  aR->val = 7;
  aLbL->val = 1;
  aLbR->val = 3;

  int val = 5;
  Solution s1;
  TreeNode* ans = s1.insertIntoBST(root, val);
  
  return 0;
}
