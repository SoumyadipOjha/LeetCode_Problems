/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check2(TreeNode* root, ListNode* head) {
        if (head == NULL)
            return 1;
        if (root) {
            if (head->val == root->val) {
                return (check2(root->left, head->next) ||
                        check2(root->right, head->next));
            }
        }

        return 0;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return 0;
        if (head->val == root->val) {
            if (check2(root, head))
                return 1;
        }

        return (isSubPath(head, root->left) || isSubPath(head, root->right));
    }
};