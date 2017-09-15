class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next)
                return head;
            
            int num = 0;
            ListNode* ptr = head;

            while (ptr) {
                num++;
                ptr = ptr->next;
            }

            ptr = head;

            for (int i = 0;i < num / 2 - 1;i++) 
                ptr = ptr->next;
            
            ListNode* head1 = ptr->next;
            ptr->next = NULL;

            ListNode* ptr1 = sortList(head);
            ListNode* ptr2 = sortList(head1);
            ListNode* newHead = NULL;
            ListNode* tail = NULL;

            while (ptr1 && ptr2) {
                if (ptr1->val < ptr2->val)
                    merge(newHead, tail, ptr1, ptr2);
                else
                    merge(newHead, tail, ptr2, ptr1);
            }

            if (ptr1)
                tail->next = ptr1;
            if (ptr2)
                tail->next = ptr2;
            
            return newHead;
        }

        void merge(ListNode*& head, ListNode*& tail, ListNode*& ptr1, ListNode*& ptr2) {
            if (!head) {
                head = ptr1;
                tail = ptr1;
                ptr1 = ptr1->next;
                tail->next = NULL;
            } else {
                tail->next = ptr1;
                tail = tail->next;
                ptr1 = ptr1->next;
                tail->next = NULL;
            }
        }
};