class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* ptr1 = head;
            ListNode* ptr2 = NULL;

            while (ptr1 != NULL) {
                if (ptr1->next != NULL && ptr1->val == ptr1->next->val) {
                    int t = ptr1->val;

                    while (ptr1 != NULL && ptr1->val == t) {
                        ListNode* ptr3 = ptr1;

                        if (ptr2 != NULL)
                            ptr2->next = ptr1->next;
                        ptr1 = ptr1->next;
                        delete ptr3;
                    }

                    if (ptr2 == NULL)
                        head = ptr1;
                } else {
                    ptr2 = ptr1;
                    ptr1 = ptr1->next;
                }
            }

            return head;
         }
};