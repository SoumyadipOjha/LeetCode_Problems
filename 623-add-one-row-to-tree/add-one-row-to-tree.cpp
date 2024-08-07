/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        vector<pair<TreeNode*, int>> stack = {{root, 1}};
        while (!stack.empty()) {
            auto [node, level] = stack.back();
            stack.pop_back();
            if (level == depth - 1) {
                TreeNode* ptr = node->left;
                node->left = new TreeNode(val, ptr, NULL);

                ptr = node->right;
                node->right = new TreeNode(val, NULL, ptr);
            } else {
                if (node->right)
                    stack.emplace_back(node->right, level + 1);
                if (node->left)
                    stack.emplace_back(node->left, level + 1);
            }
        }
        return root;
    }
};
