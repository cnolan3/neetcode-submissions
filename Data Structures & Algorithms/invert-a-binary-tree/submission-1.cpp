/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        
        vector<TreeNode*> stck;

        stck.push_back(root);

        while (!stck.empty()) {
            TreeNode* top = stck.back();
            stck.pop_back();

            TreeNode* tmp = top->left;
            top->left = top->right;
            top->right = tmp;

            if (top->right) stck.push_back(top->right);
            if (top->left) stck.push_back(top->left);
        }

        return root;
    }
};
