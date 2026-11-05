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
    int diameterOfBinaryTree(TreeNode* root) {
        int res;
        diameter_r(root, res);
        return res;
    }

    int diameter_r(TreeNode* node, int& res) {
        if (!node) {
            res = 0;
            return 0;
        }

        int leftRes;
        int left = diameter_r(node->left, leftRes);
        int rightRes;
        int right = diameter_r(node->right, rightRes);

        res = max((left + right), max(leftRes, rightRes));

        return (max(left, right) + 1);
    }
};
