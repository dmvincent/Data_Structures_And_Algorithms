#include <iostream>
#include <limits.h>

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
    int dfsClosest(TreeNode* root, double target, int smaller, int larger) {
      int ans;
      if(static_cast<double>(smaller) <= target  && target <= static_cast<double>(larger)) {
        double smallDiff = target - smaller;
        double largeDiff = larger - target;
        return (smallDiff < largeDiff)?smaller:larger;
      }

      if(root->val > target) {
        if(root->left == NULL)
          return root->val;
        smaller = root->left->val;
        larger = root->val;
        ans = dfsClosest(root->left, target, smaller, larger);
      }

      if(root->val < target) {
        if(root->right == NULL)
          return root->val;
        smaller = root->val;
        larger = root->right->val;
        ans = dfsClosest(root->right, target, smaller, larger);
      }
      return ans;
    }

    int closestValue(TreeNode* root, double target) {
      if(root->left == NULL && root->right == NULL)
        return root->val;
      return dfsClosest(root, target, root->val, root->val);
    }
};

int main() {
  TreeNode* aLbL = new TreeNode(1);
  TreeNode* aLbR = new TreeNode(3);
  TreeNode* aL = new TreeNode(2, aLbL, aLbR);
  TreeNode* aR = new TreeNode(5);
  TreeNode* root = new TreeNode(4, aL, aR);

  Solution s1; 
  double target = 3.714286;
  int ans = s1.closestValue(root, target);
  std::cout << "Answer: " << ans << std::endl;

  return 0; 
}
