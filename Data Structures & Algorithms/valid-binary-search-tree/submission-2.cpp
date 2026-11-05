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
    bool isValidBST(TreeNode* root) {
        return validBST_r(root, INT_MIN, INT_MAX);
    }

    bool validBST_r(TreeNode* node, int low, int high) {
        if (!node) return true;

        if (!(low < node->val && node->val < high)) return false;

        return (validBST_r(node->left, low, node->val) && validBST_r(node->right, node->val, high));
    }
};
