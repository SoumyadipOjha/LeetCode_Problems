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
    ListNode* reverseList(ListNode* head) {
        ListNode* nextNode=NULL;
        ListNode* prevNode=NULL;
        ListNode* temp=head;
        while(temp){
            nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
        }
        return prevNode;
    }
};