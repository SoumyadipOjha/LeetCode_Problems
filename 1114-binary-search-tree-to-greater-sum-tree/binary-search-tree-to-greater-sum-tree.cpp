class Solution {
private:
    void solve(TreeNode* curr, int& val) {
        if (curr == nullptr)
            return;
        solve(curr->right, val);
        val += curr->val;
        curr->val = val;
        solve(curr->left, val);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        solve(root, val);
        return root;
    }
};