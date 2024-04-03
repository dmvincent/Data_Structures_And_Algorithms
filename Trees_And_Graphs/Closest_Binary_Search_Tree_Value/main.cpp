#include <iostream>
#include <limits.h>
#include <math.h>

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
    double min = std::numeric_limits<double>::max();
    int ans;
    int dfsClosest(TreeNode* root, double target) {
      if(root == NULL) {
        return ans;
      }

      double currentMin = fabs(target - static_cast<double>(root->val));
      if(currentMin <= min) {
        if(currentMin == min) {
          ans = std::min(ans, root->val);
        } else {
          min = currentMin;
          ans = root->val;
        }
      }

      if(root->val > target) {
        ans = dfsClosest(root->left, target);        
      }

      if(root->val < target) {
        ans = dfsClosest(root->right, target);        
      }
      return ans;
    }

    int closestValue(TreeNode* root, double target) {
      if(root->left == NULL && root->right == NULL)
        return root->val;
      return dfsClosest(root, target);
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
