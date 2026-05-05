class Solution {
public:
    ListNode* reverseFirstK(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (head != nullptr) {
            head->next = curr;
        }

        return prev; 
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int size = 0;
        ListNode* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }

        k = k % size;
        if (k == 0) return head;

        head = reverseFirstK(head, size);
        ListNode* firstPart = reverseFirstK(head, k);
        ListNode* curr = firstPart;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        curr->next = reverseFirstK(curr->next, size - k);

        return firstPart;
    }
};