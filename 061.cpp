class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            int count = 0;
            ListNode* ptr = head;

            while (ptr != NULL) {
                count++;
                ptr = ptr->next;
            }

            vector<int> v(count);

            for (int i = 0;i < count;i++) 
                v[i] = (i + k) % count;
            
            int index = -1;

            for (int i = 0;i < count;i++) {
                if (v[i] == 0) {
                    index = i;
                    break;
                }
            }

            ListNode* ptr1 = NULL;
            ListNode* ptr2 = NULL;

            for (int i = 0;i <= index;i++) {
                ptr2 = ptr1;
                ptr1 = ptr1 == NULL ? head : ptr1->next;
            }

            if (ptr1 != head) {
                ptr2->next = NULL;

                ListNode* ptr3 = ptr1;

                while (ptr3->next != NULL)
                    ptr3 = ptr3->next;
                
                ptr3->next = head;
            }
            
            return ptr1;
        }
};