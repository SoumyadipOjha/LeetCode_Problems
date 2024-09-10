class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = prev->next;
        while (curr != nullptr) {
            ListNode* newNode = new ListNode(gcdEuclid(prev->val, curr->val));
            prev->next = newNode;
            newNode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }

private:
    int gcdEuclid(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
