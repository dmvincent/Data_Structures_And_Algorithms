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
//    int dfs(TreeNode* root) {
//        int count = 1;
//        // Provide Base Case
//        if (root == NULL) {
//            return 0;
//        }
//        int left = dfs(root->left);
//        int right = dfs(root->right);
//        int longer = std::max(left,right);
//        return longer + count;
//    }

    int diameterOfBinaryTree(TreeNode* root) {
//        int leftCount = dfs(root->left);
//        int rightCount = dfs(root->right);
//
//        return leftCount + rightCount; 
        int count = 1;
        // Provide Base Case
        if (root == NULL) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int longer = std::max(left,right);
        return longer + count;

    }
};

int main() {
    //TreeNode aLbL(4);
    //TreeNode aLbR(5);
    //TreeNode aL(2);
    //TreeNode aR(3);
    //TreeNode root(1);

    //root.left = &aL;
    //root.right = &aR;
    //aL.left = &aLbL;
    //aL.right = &aLbR;

    TreeNode root(1);
    TreeNode aL(1);
    root.left = &aL;

    Solution s1;
    int ans = s1.diameterOfBinaryTree(&root);
    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
