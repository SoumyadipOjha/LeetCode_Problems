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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       vector<ListNode*>v;
       ListNode* temp=head;
       while(temp){
        v.push_back(temp);
        temp=temp->next;
       } 
       int i=0;
       int j=v.size()-1;
       while(i<j){
        if(v[i]->val!=v[j]->val){
            return false;
        }
        i++;
        j--;
       }
       return true;
    }
};