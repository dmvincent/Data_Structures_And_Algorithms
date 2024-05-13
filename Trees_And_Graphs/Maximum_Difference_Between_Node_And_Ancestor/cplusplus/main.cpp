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
    int dfs(TreeNode* root, int max, int min) {
        // Define the base case
        if(root == NULL) {
            return 0;
        }

        max = std::max(root->val, max);
        min = std::min(root->val, min);


        return 0; 
        
    }

    int maxAncestorDiff(TreeNode* root) {
        int max = root->val;
        int min = root->val;

        dfs(root->left, max, min);
        dfs(root->right, max, min);

        return 0;
    }
};

int main() {
    // Define node values
    TreeNode root(8);                   
    // Left Subtree
    TreeNode aLbL(1);                   
    TreeNode aLbRcL(4);                 
    TreeNode aLbRcR(7);                 
    TreeNode aL(3);                     
    TreeNode aLbR(6);                  
    // Right Subtree
    TreeNode aRbRcL(13);
    TreeNode aRbR(14);
    TreeNode aR(10);

    // Provide Directions
    root.left = &aL;
    root.right = &aR;
    // Left Direction
    aL.right = &aLbR;
    aL.left = &aLbL;
    aLbR.left = &aLbRcL;
    aLbR.right = &aLbRcR;
    // Right Directions
    aR.right = &aRbR;
    aRbR.left = &aRbRcL;

    // Prepare and execute call to method 
    Solution s1;
    int ans = s1.maxAncestorDiff(&root);
    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
