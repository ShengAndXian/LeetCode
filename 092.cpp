class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            ListNode* newHead = new ListNode(-1);

            newHead->next = head;

            ListNode* ptr1 = newHead;

            for (int i = 1;i < m;i++)
                ptr1 = ptr1->next;

            ListNode* ptr2 = ptr1->next;
            ListNode* ptr3 = ptr2->next;

            for (int i = m + 1;i <= n;i++) {
                ptr2->next = ptr3->next;
                ptr3->next = ptr1->next;
                ptr1->next = ptr3;
                ptr3 = ptr2->next;
            }

            return newHead->next;
        }
};