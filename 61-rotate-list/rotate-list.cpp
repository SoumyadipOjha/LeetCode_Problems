class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int size = 1;

        // get correct tail and size
        while (tail->next) {
            tail = tail->next;
            size++;
        }

        k = k % size;
        if (k == 0) return head;

        // make circular
        tail->next = head;

        ListNode* newTail = head;

        for (int i = 0; i < size - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};