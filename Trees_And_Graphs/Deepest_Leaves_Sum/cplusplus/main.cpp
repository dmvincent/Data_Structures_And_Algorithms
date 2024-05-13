#include <iostream>
#include <queue>

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
    int deepestLeavesSum(TreeNode* root) {
        // Provide Corner Case
        if(root->left == nullptr && root->right == nullptr) 
            return root->val;
        
        // Prepare Queue for storing each node value
        std::queue<TreeNode*> queue;  
        queue.push(root);
        bool hasChildren = true;

        while(!queue.empty() && hasChildren) {
            hasChildren = false;
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left != NULL) {
                    if(node->left->left != NULL || node->left->right != NULL) {
                        hasChildren = true;
                    }
                    queue.push(node->left);
                }
                if(node->right != NULL ) {
                    if(node->right->left != NULL || node->right->right != NULL) {
                        hasChildren = true;
                    }
                    queue.push(node->right);
                }
            }
        }
        int ans{0};
        while(!queue.empty()) {
            ans += queue.front()->val;
            queue.pop();
        }
        return ans;    
    }
};

int main() {
    // Define Tree Nodes row by row
    TreeNode aLbLcL(7);
    TreeNode aRbRcR(8);

    TreeNode aLbL(4);
    TreeNode aLbR(5);
    TreeNode aRbR(6);

    TreeNode aL(2);
    TreeNode aR(3);
    
    TreeNode root(1);

    // Define node relationships
    root.left = &aL;
    root.right = &aR;

    aL.left = &aLbL;
    aL.right = &aLbR;
    aR.right = &aRbR;

    aLbL.left = &aLbLcL;
    aRbR.right = &aRbRcR;

    // Call Method
    Solution s1;
    int ans = s1.deepestLeavesSum(&root);
    std::cout << "Answer: " << ans << std::endl;
}
