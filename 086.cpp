class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* head1 = NULL;
            ListNode* head2 = NULL;
            ListNode* pre1 = NULL;
            ListNode* pre2 = NULL;
            ListNode* ptr = head;

            while (ptr != NULL) {
                if (ptr->val < x) {
                    if (pre1 == NULL)
                        head1 = ptr;
                    else
                        pre1->next = ptr;
                    
                    pre1 = ptr;
                } else {
                    if (pre2 == NULL)
                        head2 = ptr;
                    else
                        pre2->next = ptr;
                    
                    pre2 = ptr;
                }

                ptr = ptr->next;
            }

            if (head1 == NULL) {
                return head2;
            } else {
                pre1->next = head2;

                if (pre2 != NULL)
                    pre2->next = NULL;
                
                return head1;
            }
        }
};