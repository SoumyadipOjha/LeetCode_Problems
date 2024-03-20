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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ath = list1; // pointer to find the ath position
        ListNode* bth = list1; // pointer to find the bth position
        while (a > 1) {        // i want the a pointer before the ath index
            ath = ath->next;
            a--;
        }
        while (b > 0) { // i want b pointer on the bth index
            bth = bth->next;
            b--;
        }
        ath->next = list2; // adding a's end to list2
        while (list2->next != NULL) {
            list2 = list2->next; // going till the end
        }
        list2->next = bth->next; // modifying links
        return list1;
    }
};
