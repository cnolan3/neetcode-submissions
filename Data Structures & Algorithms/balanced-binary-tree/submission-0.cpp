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
    bool isBalanced(TreeNode* root) {
        int h;
        return balanced_r(root, h);
    }

    bool balanced_r(TreeNode* node, int& height) {
        if (!node) {
            height = 0;
            return true;
        }

        int leftHeight;
        if (!balanced_r(node->left, leftHeight)) return false;

        int rightHeight;
        if (!balanced_r(node->right, rightHeight)) return false;

        if (std::abs(leftHeight - rightHeight) > 1) return false;

        height = (max(leftHeight, rightHeight) + 1);

        return true;
    }
};
