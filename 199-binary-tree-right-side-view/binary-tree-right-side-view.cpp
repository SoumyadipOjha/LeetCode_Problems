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
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        int maxl=INT_MIN;
        vector<int> res;
        helper(root, level, maxl, res);
        return res;
    }
    void helper(TreeNode* root, int level, int& maxl, vector<int>& res){
        if(!root) return;
        if(level>maxl) {
            res.push_back(root->val);
            maxl=level;
        }
        helper(root->right, level+1, maxl,res);
        helper(root->left, level+1, maxl,res);
    }
};