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
    int minDepth(TreeNode* root) {
        // Define the Base case
        if(root == nullptr) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return std::min(left, right) + 1;
    }
};

int main() {
    TreeNode *root = new TreeNode();
    TreeNode *aL = new TreeNode();
    TreeNode *aR = new TreeNode();
    TreeNode *aRbL = new TreeNode();
    TreeNode *aRbR = new TreeNode();

    // Provide Node Values
    root->val = 3;
    aL->val = 9;
    aR->val = 20;
    aRbL->val = 15;
    aRbR->val = 7;

    // Define Tree Layout
    root->left = aL;
    root->right = aR;

    aR->left = aRbL;
    aR->right = aRbR;
    
    Solution s1;
    int ans = s1.minDepth(root);
    std::cout << "Answer: " << ans << std::endl;
    
    return 0;
}
