class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            ListNode* newHead = new ListNode(-1);
            newHead->next = head;

            ListNode* ptr1 = head;
            ListNode* ptr2 = newHead;

            while (ptr1) {
                ListNode* ptr3 = newHead;

                while (ptr3->next != ptr1 && ptr3->next->val < ptr1->val)
                    ptr3 = ptr3->next;
                
                if (ptr3->next != ptr1) {
                    ptr2->next = ptr1->next;
                    ptr1->next = ptr3->next;
                    ptr3->next = ptr1;
                    ptr1 = ptr2->next;
                } else {
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                }
            }

            return newHead->next;
        }
};