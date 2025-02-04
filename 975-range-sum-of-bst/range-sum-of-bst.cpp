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
    int rangeSumBST(TreeNode* root, int left, int right) {
        if (!root)
            return 0;
        if (root->val >= left && root->val <= right)
            return root->val + rangeSumBST(root->left, left, right) +
                   rangeSumBST(root->right, left, right);
        else {
            return rangeSumBST(root->left, left, right) +
                   rangeSumBST(root->right, left, right);
        }
    }
};