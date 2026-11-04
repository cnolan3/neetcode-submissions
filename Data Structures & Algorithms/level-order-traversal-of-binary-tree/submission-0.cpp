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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ret;
        int curLevel = 0;

        q.push({root, 0});

        ret.push_back({});

        while (!q.empty()) {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();

            if (tmp.first->left) {
                q.push({tmp.first->left, tmp.second + 1});
            }

            if (tmp.first->right) {
                q.push({tmp.first->right, tmp.second + 1});
            }

            if (tmp.second != curLevel) {
                ret.push_back({});
                curLevel = tmp.second;
            }

            ret.back().push_back(tmp.first->val);
        }

        return ret;
    }
};
